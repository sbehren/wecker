#include "light.hpp"

#include "../enums/buttons.hpp"
#include "alarm.hpp"
#include "set_clock.hpp"
#include "set_light.hpp"

Light::Light(const char* name) : StateObject(name) {}

StateObject* Light::handle(App* app) {
  switch (app->active_button) {
    case Buttons::MODE: {
      app->display->set_chars(app->msg.alarm);
      app->light_control->save_level_set_by_user();
      app->light_control->turn_light_off();
      app->pauser.enable_one_long_pause();
      return app->state_list->alarm;
    }
    case Buttons::PLUS: {
      app->light_control->increase_light_level();
      return app->state_list->set_light;
    }
    case Buttons::MINUS: {
      app->light_control->decrease_light_level();
      return app->state_list->set_light;
    }
    case Buttons::SET: {
      app->display->set_chars(app->msg.set_clock);
      app->pauser.enable_one_long_pause();
      return app->state_list->set_clock;
    }
    default: {
      app->display_hw_time();
      return this;
    }
  }
}
