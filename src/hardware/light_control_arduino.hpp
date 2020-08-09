#pragma once

#include "light_control.hpp"

/**
 * Interface to control the hardware light
 */
class LightControlArduino: public LightControl {
 public:
  explicit LightControlArduino(const Config& config);

 protected:
  virtual void update_hw_light();
};
