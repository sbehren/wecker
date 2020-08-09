#pragma once

class Blinker {
 public:
  Blinker();
  void toggle_blinking();
  bool is_blinking() const;
 protected:
  virtual void start_blinking() = 0;
  virtual void stop_blinking() = 0;
  bool blinking;
};
