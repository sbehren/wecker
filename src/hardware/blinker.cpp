#include "blinker.hpp"

Blinker::Blinker() {
  blinking = false;
}

bool Blinker::is_blinking() const {
  return blinking;
}

void Blinker::toggle_blinking() {
  blinking = !blinking;
  if (blinking) {
    start_blinking();
  } else {
    stop_blinking();
  }
}
