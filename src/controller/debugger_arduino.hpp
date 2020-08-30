#pragma once

#include "app.hpp"
#include "debugger.hpp"
#define DISPLAY_LENGTH 5

/**
 * Interface for the debugger
 */
class DebuggerArduino : public Debugger {
 public:
  DebuggerArduino();
  virtual void show_debug_messages(const App& app);

 private:
  // TODO(Sönke): init via constexpr
  char copy_of_effective_digits[DISPLAY_LENGTH] = "    ";
};
