#pragma once

#include "state.hpp"

class App;

class Ring: public StateObject {
 public:
  explicit Ring(const char* name);
  StateObject* handle(App* app);
};
