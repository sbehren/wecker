#include "alarm.hpp"

#include "ring.hpp"
#include "set_alarm.hpp"
#include "state.hpp"

Alarm::Alarm(const char* name): StateObject(name) {}

StateObject* Alarm::handle(App* app) {
  app->display_hw_time();
  app->light_control->set_light_level_fraction(
      app->clock_manager.suggest_lighting_in_alarm());
  if (app->clock_manager.alarm_triggers()) {
    app->clock_manager.reset_effective_alarm();
    return app->state_list->ring;
  } else {
    switch (app->active_button) {
      case Buttons::MODE: {
        return app->enter_state_off();
      }
      case Buttons::SET: {
        app->display->set_chars(app->msg.set_alarm);
        app->pauser.enable_one_long_pause();
        return app->state_list->set_alarm;
      }
      default: {
        return this;
      }
    }
  }
}
