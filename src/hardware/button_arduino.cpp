#ifndef PC_ONLY
#include "button_arduino.hpp"

#include "Arduino.h"
#include "pins.hpp"

ButtonArduino::ButtonArduino() {
  // PinBinding<Buttons> mode(1, Buttons::MODE);
  // PinBinding<Buttons> set(2, Buttons::SET);
  // PinBinding<Buttons> plus(3, Buttons::PLUS);
  // PinBinding<Buttons> minus(4, Buttons::MINUS);
  // PinBinding<Buttons> snooze(5, Buttons::SNOOZE);
  // PinsAndButtons[0] = mode;
  // PinsAndButtons[1] = set;
  // PinsAndButtons[2] = plus;
  // PinsAndButtons[3] = minus;
  // PinsAndButtons[4] = snooze;
  for (int i = 0; i < num_pins_and_buttons; i++) {
    PinBinding<Buttons> pinbutton = PinsAndButtons[i];
    pinMode(pinbutton.pin, INPUT_PULLUP);
  }
}

Buttons ButtonArduino::get_button_pressed() const {
  Buttons result = Buttons::NONE;
  for (int i = 0; i < num_pins_and_buttons; i++) {
    PinBinding<Buttons> pinbutton = PinsAndButtons[i];
    if (digitalRead(pinbutton.pin)) {
      result = pinbutton.partner;
    }
  }
  return result;
}
#endif
