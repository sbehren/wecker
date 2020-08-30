#pragma once

#include <string>

#include "../controller/app.hpp"
#include "../controller/debugger.hpp"

/**
 * Interface for the debugger
 */
class DebuggerPc : public Debugger {
 public:
  DebuggerPc(int argc, char** arg);
  virtual void show_debug_messages(const App& app);
  bool get_use_mockup_clock();

 private:
  bool use_mockup_clock;
  bool verbose_debug;
};
