#include <cstdint>
#include <type_traits>
#include "k_device_register.h"

class k_rcc {
private:
    k_device_register CR;           /*!< RCC clock control register,                               Address offset: 0x00 */
    k_device_register CFGR;         /*!< RCC clock configuration register,                          Address offset: 0x04 */
    k_device_register CIR;          /*!< RCC clock interrupt register,                             Address offset: 0x08 */
    k_device_register APB2RSTR;     /*!< RCC APB2 peripheral reset register,                       Address offset: 0x0C */
    k_device_register APB1RSTR;     /*!< RCC APB1 peripheral reset register,                       Address offset: 0x10 */
    k_device_register AHBENR;       /*!< RCC AHB peripheral clock register,                        Address offset: 0x14 */
    k_device_register APB2ENR;      /*!< RCC APB2 peripheral clock enable register,                Address offset: 0x18 */
    k_device_register APB1ENR;      /*!< RCC APB1 peripheral clock enable register,                Address offset: 0x1C */
    k_device_register BDCR;         /*!< RCC Backup domain control register,                       Address offset: 0x20 */
    k_device_register CSR;          /*!< RCC clock control & status register,                      Address offset: 0x24 */
    k_device_register AHBRSTR;      /*!< RCC AHB peripheral reset register,                        Address offset: 0x28 */
    k_device_register CFGR2;        /*!< RCC clock configuration register 2,                        Address offset: 0x2C */
    k_device_register CFGR3;        /*!< RCC clock configuration register 3,                        Address offset: 0x30 */
    k_device_register CR2;          /*!< RCC clock control register 2,                             Address offset: 0x34 */
public:
    static constexpr uint32_t RCC_BASE_ADDRESS = 0x40000000UL | 0x00020000UL | 0x00001000UL;
    void *operator new(size_t) {
        auto address = RCC_BASE_ADDRESS;
        return reinterpret_cast<void *>(address);
    };
};

static_assert(
    is_standard_layout_v<k_rcc>, // trait class
    "k_rcc is not standard layout, expect problems"
);
