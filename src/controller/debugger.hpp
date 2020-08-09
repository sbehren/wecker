#pragma once

#include "app.hpp"

/**
 * Interface for the debugger
 */
class Debugger {
 public:
  virtual void show_debug_messages(const App& app) = 0;
};
