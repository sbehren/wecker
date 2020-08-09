#pragma once

#include "state.hpp"

class App;

class Light: public StateObject {
 public:
  explicit Light(const char* name);
  StateObject* handle(App* app);
};
