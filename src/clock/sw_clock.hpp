#pragma once

#include "../enums/digit_groups.hpp"

class SwClock {
 public:
  SwClock();

  int get_hours() const;
  void set_hours(int new_hours);

  int get_minutes() const;
  void set_minutes(int new_minutes);

  int serialize_to_mins() const;
  void deserialize_from_mins(int total_minutes);
  void push_minutes_ahead(int minutes);

  void set_from_other(const SwClock& clock);
  int get_minutes_ahead_of(const SwClock& clock) const;
  bool equals_other(const SwClock& clock) const;

  DigitGroups get_updating_digit_group() const;
  void reset_updating_mechanism();
  void toggle_digits_group_being_updated();
  void increase_digits_at_current_position();
  void decrease_digits_at_current_position();

  int get_readable_time() const;

 private:
  void change_digits_at_current_position(int step);

  int hours;
  int minutes;
  bool updating_hours;
};
