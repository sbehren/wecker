#include "buzzer_arduino.hpp"

BuzzerArduino::BuzzerArduino() { buzzing = false; }

void BuzzerArduino::start_buzzing() { buzzing = true; }

void BuzzerArduino::stop_buzzing() { buzzing = false; }
