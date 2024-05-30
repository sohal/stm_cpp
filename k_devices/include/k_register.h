#pragma once
#include <cstdint>

// Device register
using k_register = uint32_t volatile; // Modern CPP only
using k_vector_table = void (&)(void);
