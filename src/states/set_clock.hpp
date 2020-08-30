#pragma once

#include "state.hpp"

class App;

class SetClock : public StateObject {
 public:
  explicit SetClock(const char* name);
  StateObject* handle(App* app);
};
