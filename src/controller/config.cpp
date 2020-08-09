#include "config.hpp"

Config::Config() {
  minutes_lighting_alarm = 20;
  minutes_snooze_interval = 5;
  change_lighting_by_fraction = 0.1;
  syscall_duration_in_us = 1000;
}

int Config::get_minutes_lighting_alarm() const {
  return minutes_lighting_alarm;
}
int Config::get_minutes_snooze_interval() const {
  return minutes_snooze_interval;
}

double Config::get_change_lighting_by_fraction() const {
  return change_lighting_by_fraction;
}

int Config::get_syscall_duration_in_us() const {
  return syscall_duration_in_us;
}
