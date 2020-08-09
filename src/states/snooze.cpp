#include "snooze.hpp"

#include "ring.hpp"

Snooze::Snooze(const char* name): StateObject(name) {}

StateObject* Snooze::handle(App* app) {
  app->display_hw_time();
  app->light_control->set_light_level_fraction(
      app->clock_manager.suggest_lighting_in_snooze());
  switch (app->active_button) {
    case Buttons::NONE: {
      if (app->clock_manager.snoozed_alarm_triggers()) {
        return app->state_list->ring;
      }
      return this;
    }
    case Buttons::SNOOZE: {
      app->clock_manager.snooze_alarm();
      return this;
    }
    default: {
      app->buzzer->stop_buzzing();
      return app->enter_state_off();
    }
  }
}
