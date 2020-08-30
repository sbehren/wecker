#pragma once

#include "button.hpp"

/**
 * Interface to access buttons
 */
class ButtonPc : public Button {
 public:
  ButtonPc();
  ~ButtonPc();

 private:
  virtual Buttons get_button_pressed() const;

  void prepare_ncurses() const;
  void end_ncurses() const;
};
