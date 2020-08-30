#pragma once

#include "hw_clock.hpp"

class HwClockPc : public HwClock {
 public:
  explicit HwClockPc(bool use_mockup_clock);
  virtual void set_from_sw(SwClock clock);
  virtual void write_to_sw(SwClock *clock) const;

 private:
  void write_localtime_to_sw(SwClock *clock) const;
  bool use_mockup_clock;
};
