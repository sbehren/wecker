#pragma once

#include <string>

enum class PadDir { LEFT, RIGHT };

std::string pad_string(
    const std::string& digits,
    char fill,
    PadDir pad_direction,
    int length);
