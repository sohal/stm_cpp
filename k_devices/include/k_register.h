#pragma once
#include <cstdint>

// Device register
using k_register = uint32_t volatile; // Modern CPP only
enum class reg32_bit {
    BIT0, BIT1, BIT2, BIT3, BIT4, BIT5, BIT6, BIT7,
    BIT8, BIT9, BIT10, BIT11, BIT12, BIT13, BIT14, BIT15,
    BIT16, BIT17, BIT18, BIT19, BIT20, BIT21, BIT22, BIT23,
    BIT24, BIT25, BIT26, BIT27, BIT28, BIT29, BIT30, BIT31
};
enum class reg32_mask {
    OneBitMask          = 0x0000'0001,
    TwoBitMask          = 0x0000'0003,
    ThreeBitMask        = 0x0000'0007,
    FourBitMask         = 0x0000'000F,
    FiveBitMask         = 0x0000'001F,
    SixBitMask          = 0x0000'003F,
    SevenBitMask        = 0x0000'007F,
    EightBitMask        = 0x0000'00FF,
    NineBitMask         = 0x0000'01FF,
    TenBitMask          = 0x0000'03FF,
    ElevenBitMask       = 0x0000'07FF,
    TwelveBitMask       = 0x0000'0FFF,
    ThirteenBitMask     = 0x0000'1FFF,
    FourteenBitMask     = 0x0000'3FFF,
    FifteenBitMask      = 0x0000'7FFF,
    SixteenBitMask      = 0x0000'FFFF,
    SeventeenBitMask    = 0x0001'FFFF,
    EighteenBitMask     = 0x0003'FFFF,
    NineteenBitMask     = 0x0007'FFFF,
    TwentyBitMask       = 0x000F'FFFF,
    TwentyOneBitMask    = 0x001F'FFFF,
    TwentyTwoBitMask    = 0x003F'FFFF,
    TwentyThreeBitMask  = 0x007F'FFFF,
    TwentyFourBitMask   = 0x00FF'FFFF,
    TwentyFiveBitMask   = 0x01FF'FFFF,
    TwentySixBitMask    = 0x03FF'FFFF,
    TwentySevenBitMask  = 0x07FF'FFFF,
    TwentyEightBitMask  = 0x0FFF'FFFF,
    TwentyNineBitMask   = 0x1FFF'FFFF,
    ThirtyBitMask       = 0x3FFF'FFFF,
    ThirtyOneBitMask    = 0x7FFF'FFFF
};
class k_reg32 {
public:
    uint32_t Check_Bit(k_register& reg, reg32_bit bitPosition) {
        return reg & (static_cast<uint32_t>(reg32_mask::OneBitMask) << static_cast<uint32_t>(bitPosition));
    }
    void Set_Bit(k_register& reg, reg32_bit bitPosition) {
        reg |= (static_cast<uint32_t>(reg32_mask::OneBitMask) << static_cast<uint32_t>(bitPosition));
    }
    void Clear_Bit(k_register& reg, reg32_bit bitPosition) {
        reg &= ~(static_cast<uint32_t>(reg32_mask::OneBitMask) << static_cast<uint32_t>(bitPosition));
    }
    void Toggle_Bit(k_register& reg, reg32_bit bitPosition) {
        reg ^= (static_cast<uint32_t>(reg32_mask::OneBitMask) << static_cast<uint32_t>(bitPosition));
    }
    uint32_t Get_Mask_Value(k_register& reg, reg32_bit bitPosition, reg32_mask bitMask) {
        return (reg & (static_cast<uint32_t>(bitMask) << static_cast<uint32_t>(bitPosition)));
    }
    void Modify_Mask_Value(k_register& reg, reg32_bit bitPosition, reg32_mask bitMask, uint32_t value) {
        value &= static_cast<uint32_t>(bitMask);
        reg &= ~(static_cast<uint32_t>(bitMask) << static_cast<uint32_t>(bitPosition));
        reg |= (value << static_cast<uint32_t>(bitPosition));
    }
};

