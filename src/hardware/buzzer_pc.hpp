#pragma once

#include "buzzer.hpp"

class BuzzerPc : public Buzzer {
 public:
  BuzzerPc();
  virtual void start_buzzing();
  virtual void stop_buzzing();
};
