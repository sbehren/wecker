#include "off.hpp"

#include "../enums/buttons.hpp"
#include "light.hpp"

Off::Off(const char* name) : StateObject(name) {}

StateObject* Off::handle(App* app) {
  app->display_hw_time();
  if (app->active_button == Buttons::MODE) {
    app->display->set_chars(app->msg.light);
    app->light_control->turn_light_to_last_level_set_by_user();
    app->pauser.enable_one_long_pause();
    return app->state_list->light;
  }
  return this;
}
