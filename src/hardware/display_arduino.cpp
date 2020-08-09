#include "display_arduino.hpp"
#ifndef PC_ONLY
DisplayArduino::DisplayArduino(const Config& config) : Display(config) {
  counter = 0;
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  // bool resistorsOnSegments = false;
  byte hardwareConfig = COMMON_CATHODE;
  // bool updateWithDelays = false;
  // bool leadingZeros = false;
  // bool disableDecPoint = true;
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins);
}

void DisplayArduino::write_effective_digits() {
  // copy_effective_digits(effective_digits_copy);
  sevseg.setNumber(counter);
  // sevseg.setNumber(1234,3);
  sevseg.refreshDisplay();
  sevseg.setBrightness(100);
  counter++;
}

void DisplayArduino::refresh_display() const {
  sevseg.refreshDisplay();
  // In practice, refreshing the display seems to cause little to no overhead
  // int net_syscall_duration_ms = 1;
  // int additional_delay = syscall_duration_ms - net_syscall_duration_ms;
  // Guard against underflow
  // if (additional_delay > 0) {
  //   delay(syscall_duration_ms);
  // }
}
#endif
