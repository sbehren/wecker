#pragma once

#include "blinker.hpp"

class BlinkerArduino : public Blinker {
 public:
  BlinkerArduino();

 protected:
  virtual void start_blinking();
  virtual void stop_blinking();
};
