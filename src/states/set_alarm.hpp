#pragma once

#include "state.hpp"

class App;

class SetAlarm: public StateObject {
 public:
  explicit SetAlarm(const char* name);
  StateObject* handle(App* app);
};
