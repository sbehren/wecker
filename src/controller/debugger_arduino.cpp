#ifndef PC_ONLY
#include "debugger_arduino.hpp"

#include "Arduino.h"

DebuggerArduino::DebuggerArduino() { Serial.begin(9600); }

void DebuggerArduino::show_debug_messages(const App& app) {
  // Cheap random condition to avoid compiler warnings
  app.display->copy_effective_digits(copy_of_effective_digits);
  Serial.println(copy_of_effective_digits);
}
#endif
