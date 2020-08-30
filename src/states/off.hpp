#pragma once

#include "state.hpp"

class App;

class Off : public StateObject {
 public:
  explicit Off(const char* name);
  StateObject* handle(App* app);
};
