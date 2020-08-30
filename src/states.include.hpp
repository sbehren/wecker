Alarm alarm("ALARM");
Init init_state("INIT");
Light light("LIGHT");
Off off("OFF");
Ring ring("RING");
SetAlarm set_alarm("SET_ALARM");
SetClock set_clock("SET_CLOCK");
SetLight set_light("SET_LIGHT");
Snooze snooze("SNOOZE");

StateList state_list(&alarm, &init_state, &light, &off, &ring, &set_alarm,
                     &set_clock, &set_light, &snooze);
