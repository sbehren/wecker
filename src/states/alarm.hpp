#pragma once

#include "state.hpp"

class App;

class Alarm : public StateObject {
 public:
  explicit Alarm(const char* name);
  StateObject* handle(App* app);
};
