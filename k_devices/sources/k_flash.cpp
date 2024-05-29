#include <cstdint>
#include "k_flash.h"

void k_flash::Init(void) {
    uint32_t tmp = 0;
    k_flash &FLASH = *new k_flash;
    FLASH.ACR &= ~k_flash::ONE_WAIT_STATE;
    FLASH.ACR |= k_flash::ONE_WAIT_STATE;
    do {
        tmp = FLASH.ACR & k_flash::ONE_WAIT_STATE;
    } while (tmp != k_flash::ONE_WAIT_STATE);
}
