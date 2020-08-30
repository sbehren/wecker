#include "hw_clock_arduino.hpp"

#include "sw_clock.hpp"

HwClockArduino::HwClockArduino() { delta_minutes = 0; }

void HwClockArduino::set_from_sw(SwClock clock) {
  // Random check to avoid compiler warnings,
  // remove after implementation
  if (clock.get_minutes() < 0) {
    return;
  }
}

void HwClockArduino::write_to_sw(SwClock *clock) const {
  // Random check to avoid compiler warnings,
  // remove after implementation
  if (clock->get_minutes() < 0) {
    return;
  }
}
