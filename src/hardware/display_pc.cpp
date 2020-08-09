#ifdef PC_ONLY

#include "display_pc.hpp"

#include <ncurses.h>
#include <unistd.h>

#include <iostream>

DisplayPc::DisplayPc(const Config& config) : Display(config) {
  setvbuf(stdout, NULL, _IONBF, 0);
}

void DisplayPc::write_effective_digits() {
  erase();
  std::cout << "\r" << effective_digits;
}

void DisplayPc::refresh_display() const {
  usleep(syscall_duration_us);
}

#endif
