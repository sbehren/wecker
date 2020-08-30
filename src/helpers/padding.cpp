#ifdef PC_ONLY

#include "padding.hpp"

#include <iomanip>
#include <sstream>
#include <string>

std::string pad_string(const std::string& digits, char fill,
                       PadDir pad_direction, int length) {
  std::stringstream s;
  if (pad_direction == PadDir::RIGHT) {
    s << std::right;
  }
  s << std::setw(length) << std::setfill(fill) << digits;
  return s.str();
}

#endif
