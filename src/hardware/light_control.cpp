#include "light_control.hpp"

#include <math.h>

LightControl::LightControl(const Config& config) {
  fraction = 1.0;
  last_userdefined_fraction = 1.0;
  change_by_fraction = config.get_change_lighting_by_fraction();
}

int LightControl::get_light_level_percentage() const {
  return static_cast<int>(round(fraction * 100));
}

void LightControl::set_light_level_fraction(double new_fraction) {
  double semi_normed_fraction = fmin(1.0, new_fraction);
  fraction = fmax(0.0, semi_normed_fraction);
}

void LightControl::decrease_light_level() {
  set_light_level_fraction(fraction - change_by_fraction);
}

void LightControl::increase_light_level() {
  set_light_level_fraction(fraction + change_by_fraction);
}

void LightControl::turn_light_off() {
  set_light_level_fraction(0.0);
}

void LightControl::turn_light_to_last_level_set_by_user() {
  set_light_level_fraction(last_userdefined_fraction);
}

void LightControl::save_level_set_by_user() {
  last_userdefined_fraction = fraction;
}
