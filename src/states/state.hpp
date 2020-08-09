#pragma once

#include "../controller/app.hpp"

class App;

class StateObject {
 public:
  explicit StateObject(const char* name);
  virtual StateObject* handle(App* app) = 0;
  const char* name;
};
