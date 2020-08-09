#pragma once

#include "../controller/config.hpp"

/**
 * Interface to control the hardware light
 */
class LightControl {
 public:
  explicit LightControl(const Config& config);
  double get_light_level_fraction() const;
  int get_light_level_percentage() const;

  void set_light_level_fraction(double fraction);

  void decrease_light_level();
  void increase_light_level();

  void turn_light_off();

  void turn_light_to_last_level_set_by_user();
  void save_level_set_by_user();

 protected:
  virtual void update_hw_light() = 0;
  double fraction;
  double last_userdefined_fraction;
  double change_by_fraction;
};
