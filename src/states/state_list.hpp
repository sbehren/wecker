#pragma once

class Alarm;
class Init;
class Light;
class Off;
class Ring;
class SetAlarm;
class SetClock;
class SetLight;
class Snooze;

class StateList {
 public:
  StateList(Alarm* alarm, Init* init, Light* light, Off* off, Ring* ring,
            SetAlarm* set_alarm, SetClock* set_clock, SetLight* set_light,
            Snooze* snooze);
  Alarm* alarm;
  Init* init;
  Light* light;
  Off* off;
  Ring* ring;
  SetAlarm* set_alarm;
  SetClock* set_clock;
  SetLight* set_light;
  Snooze* snooze;
};
