#pragma once

#include "light_control.hpp"

/**
 * Interface to control the hardware light
 */
class LightControlPc : public LightControl {
 public:
  explicit LightControlPc(const Config& config);

 protected:
  virtual void update_hw_light();
};
