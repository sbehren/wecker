#ifdef PC_ONLY

#include "button_pc.hpp"

#include <ncurses.h>

ButtonPc::ButtonPc() { prepare_ncurses(); }

ButtonPc::~ButtonPc() { end_ncurses(); }

Buttons ButtonPc::get_button_pressed() const {
  int ch;
  Buttons button_pressed;

  if ((ch = getch()) == ERR) {
    button_pressed = Buttons::NONE;
  } else {
    if (ch == 'm')
      button_pressed = Buttons::MODE;
    else if (ch == 's')
      button_pressed = Buttons::SET;
    else if (ch == 'a')
      button_pressed = Buttons::MINUS;
    else if (ch == 'd')
      button_pressed = Buttons::PLUS;
    else if (ch == 'z')
      button_pressed = Buttons::SNOOZE;
    else
      button_pressed = Buttons::NONE;
  }
  flushinp();

  return button_pressed;
}

void ButtonPc::prepare_ncurses() const {
  // Prepare ncurses
  // See http://hughm.cs.ukzn.ac.za/~murrellh/os/notes/ncurses.html
  initscr();              // Init ncurses
  cbreak();               //  Line buffering disabled. pass on everything
  noecho();               // No echo
  nodelay(stdscr, TRUE);  // No delay
  // clear();  // Clear terminal
}

void ButtonPc::end_ncurses() const { endwin(); }

#endif
