#pragma once

class Buzzer {
 public:
  Buzzer();
  virtual void start_buzzing() = 0;
  virtual void stop_buzzing() = 0;
  bool is_buzzing() const;

 protected:
  bool buzzing;
};
