#pragma once
#include <cstdint>
#include <type_traits>
#include "k_address.h"
#include "k_register.h"

class k_flash {
private:
// List all HW registers
    k_register ACR;          /*!<FLASH access control register,                 Address offset: 0x00 */
    k_register KEYR;         /*!<FLASH key register,                            Address offset: 0x04 */
    k_register OPTKEYR;      /*!<FLASH OPT key register,                        Address offset: 0x08 */
    k_register SR;           /*!<FLASH status register,                         Address offset: 0x0C */
    k_register CR;           /*!<FLASH control register,                        Address offset: 0x10 */
    k_register AR;           /*!<FLASH address register,                        Address offset: 0x14 */
    k_register RESERVED;     /*!< Reserved,                                                     0x18 */
    k_register OBR;          /*!<FLASH option bytes register,                   Address offset: 0x1C */
    k_register WRPR;         /*!<FLASH option bytes register,                   Address offset: 0x20 */

private:
// constant definititons
    static constexpr uint32_t FLASH_ADDRESS_OFFSET = 0x0000'2000;
    static constexpr uint32_t FLASH_ADDRESS = k_address::AHB_BASE_ADDRESS + FLASH_ADDRESS_OFFSET;
    enum ACR_LATENCY_values {
        ZERO_WAIT_STATE,    /*!<FLASH latency value for sysclock <= 24MHz                            */
        ONE_WAIT_STATE      /*!<FLASH latency value for 24MHz < sysclock <= 48MHz                    */
    };
public:
//  object reference
    void *operator new(size_t) {
        return reinterpret_cast<void *>(FLASH_ADDRESS);
    };
//  method to initalize
    void Init(void);
};

static_assert(
    std::is_standard_layout_v<k_flash>, // trait class
    "k_flash is not standard layout, expect problems"
);
