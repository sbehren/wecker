#include "pins.hpp"

#include "../enums/buttons.hpp"

template <class T>
PinBinding<T>::PinBinding(int pin, T partner) : pin(pin), partner(partner) {}

// Explicit instantiation
template class PinBinding<Buttons>;
