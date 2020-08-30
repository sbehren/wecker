#pragma once

#include "state.hpp"

class App;

class Snooze : public StateObject {
 public:
  explicit Snooze(const char* name);
  StateObject* handle(App* app);
};
