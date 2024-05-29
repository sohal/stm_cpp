#pragma once
#include <cstdint>

// Device register
using k_register = uint32_t volatile; // Modern CPP only
enum k_bitValue {
    k_clear,
    k_set
};
