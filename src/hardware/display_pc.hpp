#pragma once

#include "display.hpp"

class DisplayPc: public Display {
 public:
  explicit DisplayPc(const Config& config);
  virtual void refresh_display() const;
  virtual void write_effective_digits();
};
