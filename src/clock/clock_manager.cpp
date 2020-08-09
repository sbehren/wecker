#include "clock_manager.hpp"

ClockManager::ClockManager(HwClock* hw_clock, const Config& config):
    hw_clock(hw_clock) {
  minutes_snooze_interval = config.get_minutes_snooze_interval();
  minutes_lighting_alarm = config.get_minutes_lighting_alarm();
  update_hw_clock_buffer();
  hw_clock->write_to_sw(&alarm);  // TODO(Sönke) DEBUG REMOVE
}

void ClockManager::reset_effective_alarm() {
  effective_alarm.set_from_other(alarm);
}

bool ClockManager::alarm_triggers() const {
  return hw_clock_buffer.equals_other(alarm);
}

bool ClockManager::snoozed_alarm_triggers() const {
  return hw_clock_buffer.equals_other(effective_alarm);
}

bool ClockManager::rings_for_too_long() const {
  int minutes_ahead = hw_clock_buffer.get_minutes_ahead_of(effective_alarm);
  return (minutes_ahead > 10);
}

void ClockManager::snooze_alarm() {
  // This approach ignores mutliple activation of snooze button
  hw_clock->write_to_sw(&effective_alarm);
  effective_alarm.push_minutes_ahead(minutes_snooze_interval);
}

void ClockManager::write_hw_clock_buffer_to_hw_clock() {
  hw_clock->set_from_sw(hw_clock_buffer);
}

void ClockManager::update_hw_clock_buffer() {
  hw_clock->write_to_sw(& hw_clock_buffer);
}

double ClockManager::suggest_lighting_in_alarm() const {
  int ahead = alarm.get_minutes_ahead_of(hw_clock_buffer);
  int reference = minutes_lighting_alarm;
  return convert_minutes_ahead_to_fraction(ahead, reference);
}

double ClockManager::suggest_lighting_in_snooze() const {
  int ahead = effective_alarm.get_minutes_ahead_of(hw_clock_buffer);
  int reference = minutes_snooze_interval;
  return convert_minutes_ahead_to_fraction(ahead, reference);
}

double ClockManager::convert_minutes_ahead_to_fraction(int ahead,
                                                       int reference) const {
  return static_cast<float>(reference - ahead) / static_cast<float>(reference);
}

SwClock ClockManager::get_effective_alarm() const {
  SwClock result;
  result.set_from_other(effective_alarm);
  return result;
}
