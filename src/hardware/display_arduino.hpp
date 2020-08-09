#pragma once
#ifndef PC_ONLY
#include "display.hpp"
#include "SevSeg.h"

class DisplayArduino: public Display {
 public:
  explicit DisplayArduino(const Config& config);
  virtual void write_effective_digits();
  virtual void refresh_display() const;
 private:
  SevSeg sevseg;
  char* effective_digits_copy = "    ";  // TODO(Sönke): Nicer way
  int counter;
};
#endif
