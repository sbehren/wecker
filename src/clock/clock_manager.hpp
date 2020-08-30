#pragma once

#include "../controller/config.hpp"
#include "hw_clock.hpp"
#include "sw_clock.hpp"

class ClockManager {
 public:
  explicit ClockManager(HwClock* hw_clock, const Config& config);

  void reset_effective_alarm();

  bool alarm_triggers() const;
  bool snoozed_alarm_triggers() const;

  void snooze_alarm();
  bool rings_for_too_long() const;

  void update_hw_clock_buffer();
  void write_hw_clock_buffer_to_hw_clock();

  double suggest_lighting_in_alarm() const;
  double suggest_lighting_in_snooze() const;

  SwClock get_effective_alarm() const;

  HwClock* hw_clock;

  SwClock alarm;
  SwClock hw_clock_buffer;

 private:
  double convert_minutes_ahead_to_fraction(int ahead, int reference) const;

  SwClock effective_alarm;
  int minutes_lighting_alarm;
  int minutes_snooze_interval;
};
