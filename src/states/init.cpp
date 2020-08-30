#include "init.hpp"

#include "light.hpp"

Init::Init(const char* name) : StateObject(name) {}

StateObject* Init::handle(App* app) {
  app->display->set_chars(app->msg.okay);
  app->pauser.enable_one_long_pause();
  return app->state_list->light;
}
