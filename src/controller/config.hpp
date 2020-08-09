#pragma once

class Config {
 public:
  Config();
  int get_minutes_snooze_interval() const;
  int get_minutes_lighting_alarm() const;
  double get_change_lighting_by_fraction() const;
  int get_syscall_duration_in_us() const;

  static constexpr int display_length = 4;

 private:
  int minutes_snooze_interval;
  int minutes_lighting_alarm;
  double change_lighting_by_fraction;
  int syscall_duration_in_us;
};
