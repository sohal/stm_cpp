#pragma once
#include <cstdint>
/**
 * @brief Class for all STM32F031x6 On Chip Memory
 * APB and AHB bus addresses are use in peripherals
 */
class k_address {
public:
    static constexpr uint32_t FLASH_BASE_ADDRESS = 0x0800'0000;
    static constexpr uint32_t FLASH_BANK1_END_ADDRESS = 0x0800'7FFF;
    static constexpr uint32_t SRAM_BASE_ADDRESS = 0x2000'0000;
    static constexpr uint32_t PERIPHERAL_BASE_ADDRESS = 0x4000'0000;
    static constexpr uint32_t APB_BASE_ADDRESS = PERIPHERAL_BASE_ADDRESS;
    static constexpr uint32_t AHB_BASE_ADDRESS = PERIPHERAL_BASE_ADDRESS + 0x0002'0000;
    static constexpr uint32_t AHB2_BASE_ADDRESS = PERIPHERAL_BASE_ADDRESS + 0x0800'0000;
};

