
#include <cstdint>
#include <type_traits>
#include "k_rcc.h"

int32_t main(void)
{
    k_rcc &RCC = *new k_rcc;
    RCC.Init_Device();
    return 0;
}
