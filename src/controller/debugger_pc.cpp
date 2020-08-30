#ifdef PC_ONLY

#include "debugger_pc.hpp"

#include <fstream>
#include <iostream>

#include "../enums/buttons.hpp"
#include "../helpers/padding.hpp"

DebuggerPc::DebuggerPc(int argc, char** arg) {
  // We want verbosity controllable from the cli
  if (argc > 1) {
    verbose_debug = (*(arg[1]) == 'v');
  } else {
    verbose_debug = true;
  }

  // We want clock mockup controllable from the cli
  if (argc > 2) {
    use_mockup_clock = (*(arg[2]) == 'm');
  } else {
    use_mockup_clock = false;
  }
}

bool DebuggerPc::get_use_mockup_clock() { return use_mockup_clock; }

void DebuggerPc::show_debug_messages(const App& app) {
  std::string state_str;
  switch (app.state) {
    case States::INIT:
      state_str = "INIT     ";
      break;
    case States::SET_ALARM:
      state_str = "SET_ALARM";
      break;
    case States::ALARM:
      state_str = "ALARM    ";
      break;
    case States::RING:
      state_str = "RING     ";
      break;
    case States::OFF:
      state_str = "OFF      ";
      break;
    case States::LIGHT:
      state_str = "LIGHT    ";
      break;
    case States::SNOOZE:
      state_str = "SNOOZE   ";
      break;
    case States::SET_LIGHT:
      state_str = "SET_LIGHT";
      break;
    case States::SET_CLOCK:
      state_str = "SET_CLOCK";
      break;
  }

  std::string button_str;
  switch (app.active_button) {
    case Buttons::MODE:
      button_str = "M";
      break;
    case Buttons::SET:
      button_str = "S";
      break;
    case Buttons::PLUS:
      button_str = "+";
      break;
    case Buttons::MINUS:
      button_str = "-";
      break;
    case Buttons::SNOOZE:
      button_str = "Z";
      break;
    case Buttons::NONE:
      button_str = " ";
      break;
  }

  std::string blinking_digits_str;
  switch (app.display->blinking_digits) {
    case DigitGroups::HOURS: {
      blinking_digits_str = "HORS";
      break;
    }
    case DigitGroups::MINUTES: {
      blinking_digits_str = "MINS";
      break;
    }
    case DigitGroups::NONE: {
      blinking_digits_str = "NONE";
      break;
    }
  }

  if (verbose_debug) {
    std::string time_string = std::to_string(app.hw_clock->delta_minutes);
    std::string light_level =
        std::to_string(app.light_control->get_light_level_percentage());
    std::string light_string = pad_string(light_level, ' ', PadDir::LEFT, 4);
    std::string buzz_string =
        app.buzzer->is_buzzing() ? "RINGRING" : "        ";

    std::cout << "\tSTATE: " << state_str << "\tBUTTON: " << button_str
              << "\tALARM: " << app.clock_manager.alarm.get_readable_time()
              << "\tSNOOZE: "
              << app.clock_manager.get_effective_alarm().get_readable_time()
              << "\tHW_CL_BUF: "
              << app.clock_manager.hw_clock_buffer.get_readable_time()
              << "\tDELTA_T: " << pad_string(time_string, ' ', PadDir::LEFT, 6)
              << "\tBRIGHT: " << light_string << "\tBUZZ: " << buzz_string;
    // << "\tBLINK: " << app.blinker->is_blinking();
  }
}

#endif
