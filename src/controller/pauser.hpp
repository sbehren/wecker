#pragma once

#include "config.hpp"
#include "../hardware/display.hpp"

class Pauser {
 public:
  Pauser(const Config& config, Display* display);
  void pause();
  void reset_pause();
  void enable_one_long_pause();
  void enable_one_medium_pause();
 protected:
  void wait_milliseconds(int milliseconds);
  void wait_through_display_refresh();

  Display* display;
  int syscall_duration_us;
  const int pause_long_ms = 1000;
  const int pause_medium_ms = 500;
  const int pause_short_ms = 200;
  bool pause_long;
  bool pause_medium;
};
