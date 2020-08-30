#include "state_list.hpp"

StateList::StateList(Alarm* alarm, Init* init, Light* light, Off* off,
                     Ring* ring, SetAlarm* set_alarm, SetClock* set_clock,
                     SetLight* set_light, Snooze* snooze)
    : alarm(alarm),
      init(init),
      light(light),
      off(off),
      ring(ring),
      set_alarm(set_alarm),
      set_clock(set_clock),
      set_light(set_light),
      snooze(snooze) {}
