#include "set_alarm.hpp"

#include "alarm.hpp"

SetAlarm::SetAlarm(const char* name) : StateObject(name) {}

StateObject* SetAlarm::handle(App* app) {
  if (app->update_clock(&app->clock_manager.alarm, false)) {
    return app->state_list->alarm;
  }
  return this;
}
