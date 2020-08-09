#pragma once

#include "sw_clock.hpp"

class HwClock {
 public:
  virtual void set_from_sw(SwClock clock) = 0;
  virtual void write_to_sw(SwClock *clock) const = 0;
  int delta_minutes;  // TODO(Sönke) Remove one day
};
