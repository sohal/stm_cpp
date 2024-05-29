#include <cstdint>
#include <bitset>
#include <cstddef>
#include "k_rcc.h"

void k_rcc::Init(void) {
    uint32_t tmp = 0;
    k_rcc &RCC = *new k_rcc;
    RCC.APB2ENR |= k_rcc::APB2ENR_SYSCFGCOMPEN;
    do {
        tmp = RCC.APB2ENR & k_rcc::APB2ENR_SYSCFGCOMPEN;
    } while (tmp != k_rcc::APB2ENR_SYSCFGCOMPEN);
    RCC.APB1ENR |= k_rcc::APB1ENR_PWREN;
    do {
        tmp = RCC.APB1ENR & k_rcc::APB1ENR_PWREN;
    } while (tmp != k_rcc::APB1ENR_PWREN);
}
