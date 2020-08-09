#pragma once

#include "../enums/buttons.hpp"

template <class T>
class PinBinding {
 public:
  PinBinding(int pin, T partner);
  int pin;
  T partner;
};
