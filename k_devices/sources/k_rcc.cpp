#include <cstdint>
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
#if 0
void k_rcc::enable_HSI(void) {

    uint32_t tmp = 0;
    k_rcc &RCC = *new k_rcc;
    RCC.CR |= k_rcc::CR_HSION;
    do {
        ;
    } while(!(RCC.CR & CR_HSIRDY));
    RCC.CR |= set_CR_HSITRIM_value(16);
    RCC.CFGR |= set_CFGR_value()
    LL_RCC_PLLSOURCE_HSI_DIV_2
    LL_RCC_PLL_MUL_12
    
}
#endif