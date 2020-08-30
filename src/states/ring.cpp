#include "ring.hpp"

#include "../enums/buttons.hpp"
#include "snooze.hpp"

Ring::Ring(const char* name) : StateObject(name) {}

StateObject* Ring::handle(App* app) {
  StateObject* next_state = this;
  app->display_hw_time();
  bool ringing_should_stop = false;
  switch (app->active_button) {
    case Buttons::NONE: {
      if (app->clock_manager.rings_for_too_long()) {
        ringing_should_stop = true;
      } else {
        app->buzzer->start_buzzing();
      }
      break;
    }
    case Buttons::SNOOZE: {
      next_state = app->state_list->snooze;
      app->buzzer->stop_buzzing();
      app->clock_manager.snooze_alarm();
      app->display->set_chars(app->msg.snooze);
      break;
    }
    default: {
      ringing_should_stop = true;
      break;
    }
  }
  if (ringing_should_stop) {
    app->buzzer->stop_buzzing();
    next_state = app->enter_state_off();
  }

  return next_state;
}
