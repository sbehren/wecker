#pragma once

#include "state.hpp"

class App;

class SetLight: public StateObject {
 public:
  explicit SetLight(const char* name);
  StateObject* handle(App* app);
};
