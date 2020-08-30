// Copyright 2019-2020 Sönke Behrends
#include "src/controller/app.hpp"
#include "src/controller/config.hpp"
#include "src/controller/debugger_arduino.hpp"

#include "src/clock/hw_clock_arduino.hpp"
#include "src/hardware/blinker_arduino.hpp"
#include "src/hardware/button_arduino.hpp"
#include "src/hardware/buzzer_arduino.hpp"
#include "src/hardware/display_arduino.hpp"
#include "src/hardware/light_control_arduino.hpp"

#include "src/headers.include.hpp"

BlinkerArduino blinker;
ButtonArduino buttons;
BuzzerArduino buzzer;
Config config;
DebuggerArduino debugger;
DisplayArduino display(config);
HwClockArduino hw_clock;
LightControlArduino light_control(config);

#include "src/states.include.hpp"

App app(
    &blinker,
    &buttons,
    &buzzer,
    &config,
    &display,
    &hw_clock,
    &light_control,
    &state_list
asdf spam spam
);

void setup() {
}

void loop() {
  #include "src/loop.include.hpp"
}
