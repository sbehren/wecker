#ifdef PC_ONLY

#include "hw_clock_pc.hpp"

#include <ctime>
#include <fstream>

#include "sw_clock.hpp"

HwClockPc::HwClockPc(bool use_mockup_clock):
    use_mockup_clock(use_mockup_clock) {
  delta_minutes = 0;
}

void HwClockPc::set_from_sw(SwClock clock) {
  // Does not actually alter system time but stores delta of minutes instead.
  SwClock now;
  write_localtime_to_sw(&now);
  delta_minutes = clock.serialize_to_mins() - now.serialize_to_mins();
}

void HwClockPc::write_to_sw(SwClock *clock) const {
  write_localtime_to_sw(clock);
  clock->push_minutes_ahead(delta_minutes);
}

void HwClockPc::write_localtime_to_sw(SwClock *clock) const {
  int hours;
  int minutes;
  if (use_mockup_clock) {
    std::ifstream clock_file;
    clock_file.open("clock_mockup.txt");
    clock_file >> hours;
    clock_file >> minutes;
  } else {
    std::time_t t = std::time(0);
    std::tm *now;
    now = std::localtime(&t);
    hours = now->tm_hour;
    minutes = now->tm_min;
  }
  clock->set_hours(hours);
  clock->set_minutes(minutes);
}

#endif
