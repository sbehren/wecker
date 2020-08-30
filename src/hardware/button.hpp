#pragma once

#include "../enums/buttons.hpp"

/**
 * Interface to access buttons.
 *
 * To model long press action (only for in- and decreasing),
 * we distinguish between pressed and active buttons.
 * A button is pressed if the user presses the key.
 * A button is active if we allow the action to proceed.
 */
class Button {
 public:
  Button();

  Buttons get_button_action();

 private:
  virtual Buttons get_button_pressed() const = 0;

  /**
   * Currently pressed button
   */
  Buttons current_button;

  /**
   * The button that was pressed before the currently pressed button
   */
  Buttons last_button;
};
