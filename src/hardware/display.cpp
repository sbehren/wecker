#include "display.hpp"

#include <stdio.h>
#include <string.h>

#include "../clock/sw_clock.hpp"

Display::Display(const Config& config) {
  display_length = config.display_length;
  syscall_duration_us = config.get_syscall_duration_in_us();
  reset_blinking();
}

void Display::set_integer(const int& num) {
  snprintf(digits, display_length+1, "%*d", display_length, num);
}

void Display::set_padded_integer(const int& num) {
  snprintf(digits, display_length+1, "%0*d", display_length, num);
}

void Display::set_clock(const SwClock& sw_clock) {
  int result = sw_clock.get_hours() * 100 + sw_clock.get_minutes();
  set_padded_integer(result);
}

void Display::set_chars(const char* chars) {
  snprintf(digits, display_length+1, "%*s", display_length, chars);
}

void Display::draw_digits() {
  // To protect the original digits, we make a copy blink.
  strncpy(effective_digits, digits, DISPLAY_LENGTH);

  if (blinking_digits != DigitGroups::NONE) {
    if (this_print_do_blink) {
      int offset = 0;
      if (blinking_digits == DigitGroups::MINUTES) {
        offset = 2;
      }
      for (int i = 0; i < 2; i++) {
        effective_digits[offset + i] = ' ';
      }
    }
    this_print_do_blink = !this_print_do_blink;
  }

  write_effective_digits();
}

void Display::copy_effective_digits(char* target) {
  strncpy(target, effective_digits, DISPLAY_LENGTH);
}

void Display::reset_blinking() {
  blinking_digits = DigitGroups::NONE;
  this_print_do_blink = false;
}
void Display::show_greeter() {
  // TODO(Sönke) implement
}
