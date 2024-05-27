#pragma once
#include <cstdint>
#include <type_traits>
#include "k_device_register.h"

//registers for GPIO for STM32

class k_gpio{
private:
    k_device_register MODR;         // offset 0x00 GPIO port mode register
    k_device_register OTYPER;       // offset 0x04 GPIO port output type register
    k_device_register OSPEEDR;      // offset 0x08 GPIO port output speed register
    k_device_register PUPDR;        // offset 0x00 GPIO port
    k_device_register IDR;          // offset 0x00 GPIO port
    k_device_register ODR;          // offset 0x00 GPIO port
    k_device_register BSRR;         // offset 0x00 GPIO port
    k_device_register LCKR;         // offset 0x00 GPIO port
    k_device_register AFRL;         // offset 0x00 GPIO port
    k_device_register AFRH;         // offset 0x00 GPIO port
    k_device_register BRR;          // offset 0x00 GPIO port
public:
    enum k_gpio_port_type {
        PORTA,
        PORTB,
        PORTC,
        PORTD,
        PORTE,
        PORTF
    };
    enum k_gpio_pin_number_type {
        PIN_0,
        PIN_1,
        PIN_2,
        PIN_3,
        PIN_4,
        PIN_5,
        PIN_6,
        PIN_7,
        PIN_8,
        PIN_9,
        PIN_10,
        PIN_11,
        PIN_12,
        PIN_13,
        PIN_14,
        PIN_15,
        PIN_16,
        PIN_17,
        PIN_18,
        PIN_19,
        PIN_20,
        PIN_21,
        PIN_22,
        PIN_23,
        PIN_24,
        PIN_25,
        PIN_26,
        PIN_27,
        PIN_28,
        PIN_29,
        PIN_30,
        PIN_31
    };
    enum k_gpio_type {
        IN,
        OUT,
    };
    void *operator new(size_t, k_gpio_port_type p) {
        auto address = 0x4800'0000 + p * 0x0000'0400;
        return reinterpret_cast<void *>(address);
    };
};

static_assert(
    is_standard_layout_v<k_gpio>, //trait class
    "k_gpio is not standard layout, expect problems"
);
