#pragma once

#include "state.hpp"

class App;

class Init : public StateObject {
 public:
  explicit Init(const char* name);
  StateObject* handle(App* app);
};
