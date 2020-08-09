#include "set_clock.hpp"

#include "light.hpp"

SetClock::SetClock(const char* name): StateObject(name) {}

StateObject* SetClock::handle(App* app) {
  if (app->update_clock(&(app->clock_manager.hw_clock_buffer), true)) {
      return app->state_list->light;
  }
  return this;
}
