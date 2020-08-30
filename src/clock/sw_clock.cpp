#include "sw_clock.hpp"

#include "../helpers/math.hpp"

/**
 * A software clock has hours and minutes but does not increase as time passes.
 */

SwClock::SwClock() {
  set_hours(0);
  set_minutes(0);
  updating_hours = true;
}

int SwClock::get_hours() const { return hours; }

void SwClock::set_hours(int new_hours) {
  hours = positive_modulo(new_hours, 24);
}

int SwClock::get_minutes() const { return minutes; }

void SwClock::set_minutes(int new_minutes) {
  minutes = positive_modulo(new_minutes, 60);
}

int SwClock::serialize_to_mins() const { return 60 * hours + minutes; }

void SwClock::deserialize_from_mins(int total_minutes) {
  const unsigned int mins_per_day = 24 * 60;
  unsigned int safe_total_mins = positive_modulo(total_minutes, mins_per_day);

  int new_hours = safe_total_mins / 60;
  set_hours(new_hours);

  int new_minutes = positive_modulo(safe_total_mins, 60);
  set_minutes(new_minutes);
}

void SwClock::push_minutes_ahead(int new_minutes) {
  int new_total_minutes = serialize_to_mins() + new_minutes;
  deserialize_from_mins(new_total_minutes);
}

void SwClock::set_from_other(const SwClock& clock) {
  set_minutes(clock.get_minutes());
  set_hours(clock.get_hours());
}

int SwClock::get_minutes_ahead_of(const SwClock& clock) const {
  int diff = serialize_to_mins() - clock.serialize_to_mins();
  return positive_modulo(diff, 24 * 60);
}

bool SwClock::equals_other(const SwClock& clock) const {
  return (get_minutes_ahead_of(clock) == 0);
}

int SwClock::get_readable_time() const { return hours * 100 + minutes; }

DigitGroups SwClock::get_updating_digit_group() const {
  return updating_hours ? DigitGroups::HOURS : DigitGroups::MINUTES;
}

void SwClock::reset_updating_mechanism() { updating_hours = true; }

void SwClock::toggle_digits_group_being_updated() {
  updating_hours = !updating_hours;
}

void SwClock::increase_digits_at_current_position() {
  int step = 1;
  change_digits_at_current_position(step);
}

void SwClock::decrease_digits_at_current_position() {
  int step = -1;
  change_digits_at_current_position(step);
}

void SwClock::change_digits_at_current_position(int step) {
  if (updating_hours) {
    set_hours(hours + step);
  } else {
    set_minutes(minutes + step);
  }
}
