#include "pauser.hpp"

Pauser::Pauser(const Config& config, Display* display) : display(display) {
  syscall_duration_us = config.get_syscall_duration_in_us();
  reset_pause();
}

void Pauser::pause() {
  if (pause_long) {
    wait_milliseconds(pause_long_ms);
  } else if (pause_medium) {
    wait_milliseconds(pause_medium_ms);
  } else {
    wait_milliseconds(pause_short_ms);
  }
}

void Pauser::reset_pause() {
  pause_long = false;
  pause_medium = false;
}

void Pauser::enable_one_long_pause() {
  pause_long = true;
}

void Pauser::enable_one_medium_pause() {
  pause_medium = true;
}

void Pauser::wait_milliseconds(int milliseconds) {
  // To refresh the display causes time penalties.
  // So we use this effect to wait in the loop.
  // Note: Standard delay()-ing would lead to flicker.
  const int scaling_factor = 1000;
  int chunks = milliseconds * scaling_factor / syscall_duration_us;
  int mod = milliseconds % syscall_duration_us;
  // Ensure we wait in case of fractionalities
  if (mod > 0) {
    chunks++;
  }
  for (int i = 0; i < chunks; i++) {
    wait_through_display_refresh();
  }
}

void Pauser::wait_through_display_refresh() {
  display->refresh_display();
}
