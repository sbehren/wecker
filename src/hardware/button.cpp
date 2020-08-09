#include "button.hpp"

Button::Button() {
  current_button = Buttons::NONE;
  last_button = Buttons::NONE;
}

Buttons Button::get_button_action() {
  Buttons active_button = Buttons::NONE;

  last_button = current_button;
  current_button = get_button_pressed();

  // Allow long-press action for plus/minus
  if ((current_button == Buttons::MINUS) || (current_button == Buttons::PLUS)) {
    if (current_button == last_button) {
      active_button = current_button;
    }
  }

  // Else a button is only active if it was previously not pressed.
  if (current_button != last_button) {
    active_button = current_button;
  }

  return active_button;
}
