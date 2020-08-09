#pragma once

#include "../controller/config.hpp"
#include "../clock/sw_clock.hpp"

#define DISPLAY_LENGTH 5

/**
 * Interface for a device that can display four digits
 */
class Display {
 public:
  explicit Display(const Config& config);

  void draw_digits();
  virtual void refresh_display() const = 0;
  void reset_blinking();

  void set_integer(const int& num);
  void set_padded_integer(const int& num);
  void set_clock(const SwClock& sw_clock);
  void set_chars(const char* chars);

  void copy_effective_digits(char* target);
  void show_greeter();

  DigitGroups blinking_digits;
  bool this_print_do_blink;

 protected:
  virtual void write_effective_digits() = 0;

  char digits[DISPLAY_LENGTH] = "    ";  // TODO(Sönke): init via constexpr
  char effective_digits[DISPLAY_LENGTH] = "    ";  // TODO(Sönke): same here
  int display_length;
  int syscall_duration_us;
};
