#ifndef PC_ONLY
#include "blinker_arduino.hpp"

#include "Arduino.h"

BlinkerArduino::BlinkerArduino() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void BlinkerArduino::start_blinking() {
  digitalWrite(LED_BUILTIN, HIGH);
}

void BlinkerArduino::stop_blinking() {
  digitalWrite(LED_BUILTIN, LOW);
}
#endif
