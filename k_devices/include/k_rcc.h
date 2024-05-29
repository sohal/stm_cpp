#include <cstdint>
#include <type_traits>
#include "k_address.h"
#include "k_register.h"

class k_rcc {
private:
// List all RCC HW registers
    k_register CR;          /*!< RCC clock control register,                   Address offset: 0x00 */
    k_register CFGR;        /*!< RCC clock configuration register,              Address offset: 0x04 */
    k_register CIR;         /*!< RCC clock interrupt register,                 Address offset: 0x08 */
    k_register APB2RSTR;    /*!< RCC APB2 peripheral reset register,           Address offset: 0x0C */
    k_register APB1RSTR;    /*!< RCC APB1 peripheral reset register,           Address offset: 0x10 */
    k_register AHBENR;      /*!< RCC AHB peripheral clock register,            Address offset: 0x14 */
    k_register APB2ENR;     /*!< RCC APB2 peripheral clock enable register,    Address offset: 0x18 */
    k_register APB1ENR;     /*!< RCC APB1 peripheral clock enable register,    Address offset: 0x1C */
    k_register BDCR;        /*!< RCC Backup domain control register,           Address offset: 0x20 */
    k_register CSR;         /*!< RCC clock control & status register,          Address offset: 0x24 */
    k_register AHBRSTR;     /*!< RCC AHB peripheral reset register,            Address offset: 0x28 */
    k_register CFGR2;       /*!< RCC clock configuration register 2,            Address offset: 0x2C */
    k_register CFGR3;       /*!< RCC clock configuration register 3,            Address offset: 0x30 */
    k_register CR2;         /*!< RCC clock control register 2,                 Address offset: 0x34 */

private:
// constant definititons of rcc
    static constexpr uint32_t RCC_ADDRESS_OFFSET = 0x0000'1000;
    static constexpr uint32_t RCC_ADDRESS = k_address::AHB_BASE_ADDRESS + RCC_ADDRESS_OFFSET;
    static constexpr uint32_t APB2ENR_SYSCFGCOMPEN_Pos = 0;
    static constexpr uint32_t APB2ENR_SYSCFGCOMPEN = (1 << APB2ENR_SYSCFGCOMPEN_Pos);
    static constexpr uint32_t APB1ENR_PWREN_Pos = 28;
    static constexpr uint32_t APB1ENR_PWREN = (1 << APB1ENR_PWREN_Pos);
public:
//  object reference
    void *operator new(size_t) {
        return reinterpret_cast<void *>(RCC_ADDRESS);
    };
//  method to initalize RCC
    void Init(void);
};

static_assert(
    std::is_standard_layout_v<k_rcc>, // trait class
    "k_rcc is not standard layout, expect problems"
);
