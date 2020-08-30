#pragma once

#include "hw_clock.hpp"

class HwClockArduino : public HwClock {
 public:
  HwClockArduino();
  virtual void set_from_sw(SwClock clock);
  virtual void write_to_sw(SwClock *clock) const;
};
