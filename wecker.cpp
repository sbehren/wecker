// Copyright 2019-2020 Sönke Behrends
#ifdef PC_ONLY  // Without this guard, arduino-builder includes this file

#include "src/clock/hw_clock_pc.hpp"

#include "src/controller/app.hpp"
#include "src/controller/debugger_pc.hpp"
#include "src/controller/config.hpp"

#include "src/hardware/blinker_pc.hpp"
#include "src/hardware/button_pc.hpp"
#include "src/hardware/buzzer_pc.hpp"
#include "src/hardware/display_pc.hpp"
#include "src/hardware/light_control_pc.hpp"

#include "src/headers.include.hpp"

int main(int argc, char** arg) {
  BlinkerPc blinker;
  ButtonPc buttons;
  BuzzerPc buzzer;
  Config config;
  DebuggerPc debugger(argc, arg);
  DisplayPc display(config);
  HwClockPc hw_clock(debugger.get_use_mockup_clock());
  LightControlPc light_control(config);

  #include "src/states.include.hpp"

  App app(
    &blinker,
    &buttons,
    &buzzer,
    &config,
    &display,
    &hw_clock,
    &light_control,
    &state_list);

  while (true) {
    #include "src/loop.include.hpp"
  }

  return 0;
}
#endif
