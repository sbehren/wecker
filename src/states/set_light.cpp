#include "set_light.hpp"

#include "light.hpp"

SetLight::SetLight(const char* name) : StateObject(name) {}

StateObject* SetLight::handle(App* app) {
  app->display->set_integer(app->light_control->get_light_level_percentage());
  app->pauser.enable_one_medium_pause();
  return app->state_list->light;
}
