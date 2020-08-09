#pragma once

#include "config.hpp"
#include "messenger.hpp"
#include "pauser.hpp"

#include "../clock/clock_manager.hpp"
#include "../clock/hw_clock.hpp"
#include "../clock/sw_clock.hpp"

#include "../hardware/blinker.hpp"
#include "../hardware/button.hpp"
#include "../hardware/buzzer.hpp"
#include "../hardware/display.hpp"
#include "../hardware/light_control.hpp"

#include "../states/state_list.hpp"

#include "../enums/states.hpp"

class StateObject;

class App {
 public:
  App(
    Blinker* binker,
    Button* buttons,
    Buzzer* buzzer,
    Config* config,
    Display* display,
    HwClock* hw_clock,
    LightControl* light,
    StateList* state_list);

  void display_hw_time();
  StateObject* enter_state_off();
  void react_to_buttons();
  void set_state(StateObject* new_state);
  void stop_buzzing();
  bool update_clock(SwClock *clock, bool write_to_hw_clock);

  Blinker* blinker;
  Button* buttons;
  Buzzer* buzzer;
  Config* config;
  Display* display;
  HwClock* hw_clock;
  LightControl* light_control;
  StateList* state_list;

  Pauser pauser = Pauser(*config, display);
  Messenger msg;

  ClockManager clock_manager = ClockManager(hw_clock, *config);

  Buttons active_button;
  States state;
  StateObject* stateobj;

 private:
};
