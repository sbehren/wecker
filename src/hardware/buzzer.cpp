#include "buzzer.hpp"

Buzzer::Buzzer() {
  buzzing = false;
}

bool Buzzer::is_buzzing() const {
  return buzzing;
}
