#pragma once

#include "buzzer.hpp"

class BuzzerArduino : public Buzzer {
 public:
  BuzzerArduino();
  virtual void start_buzzing();
  virtual void stop_buzzing();
};
