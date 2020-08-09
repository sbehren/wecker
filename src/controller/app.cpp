#include "app.hpp"

#include "../states/state.hpp"
#include "../states/alarm.hpp"
#include "../states/init.hpp"
#include "../states/light.hpp"
#include "../states/off.hpp"
#include "../states/ring.hpp"
#include "../states/set_alarm.hpp"
#include "../states/set_clock.hpp"
#include "../states/set_light.hpp"
#include "../states/snooze.hpp"

#include "../enums/digit_groups.hpp"

App::App(
    Blinker* blinker,
    Button* buttons,
    Buzzer* buzzer,
    Config* config,
    Display* display,
    HwClock* hw_clock,
    LightControl* light_control,
    StateList* state_list) :
    blinker(blinker),
    buttons(buttons),
    buzzer(buzzer),
    config(config),
    display(display),
    hw_clock(hw_clock),
    light_control(light_control),
    state_list(state_list) {
    clock_manager = ClockManager(hw_clock, *config);
    state = States::INIT;
    stateobj = state_list->init;
}


void App::react_to_buttons() {
  active_button = buttons->get_button_action();
  stateobj = stateobj->handle(this);
}

// Avoid code duplication
StateObject* App::enter_state_off() {
  display->set_chars(msg.off);
  light_control->turn_light_off();
  pauser.enable_one_long_pause();
  return state_list->off;
}

void App::display_hw_time() {
  clock_manager.update_hw_clock_buffer();
  display->set_clock(clock_manager.hw_clock_buffer);
}

bool App::update_clock(
    SwClock *clock,
    bool write_to_hw_clock) {
  bool done = false;
  display->blinking_digits = clock->get_updating_digit_group();
  switch (active_button) {
    case Buttons::MODE: {
      clock->toggle_digits_group_being_updated();
      break;
    }
    case Buttons::SET: {
      done = true;
      clock->reset_updating_mechanism();
      display->reset_blinking();
      display->set_chars(msg.okay);
      if (write_to_hw_clock) {
        clock_manager.write_hw_clock_buffer_to_hw_clock();
      }

      pauser.enable_one_long_pause();
      break;
    }
    case Buttons::PLUS: {
      clock->increase_digits_at_current_position();
      display->set_clock(*clock);
      break;
    }
    case Buttons::MINUS: {
      clock->decrease_digits_at_current_position();
      display->set_clock(*clock);
      break;
    }
    default: {
      display->set_clock(*clock);
      break;
    }
  }
  return done;
}
