#pragma once

#include "blinker.hpp"

class BlinkerPc: public Blinker {
 public:
  BlinkerPc();
 protected:
  virtual void start_blinking();
  virtual void stop_blinking();
};
