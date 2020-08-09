#include "buzzer_pc.hpp"

BuzzerPc::BuzzerPc() {
  buzzing = false;
}

void BuzzerPc::start_buzzing() {
  buzzing = true;
}

void BuzzerPc::stop_buzzing() {
  buzzing = false;
}
