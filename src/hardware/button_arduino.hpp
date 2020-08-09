#pragma once

#include "button.hpp"

#include "pins.hpp"

/**
 * Interface to access buttons
 */
class ButtonArduino: public Button {
 public:
  ButtonArduino();
 private:
  static const int num_pins_and_buttons = 5;
  virtual Buttons get_button_pressed() const;
  PinBinding<Buttons> PinsAndButtons[num_pins_and_buttons] = {
      {1, Buttons::MODE},
      {2, Buttons::SET},
      {3, Buttons::PLUS},
      {4, Buttons::MINUS},
      {5, Buttons::SNOOZE} };
};
