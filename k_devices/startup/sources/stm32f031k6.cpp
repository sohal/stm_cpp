
#include <cstdint>
#include "stm32f031k6.h"
#ifdef __cplusplus
extern "C" {
#endif
/*---------------------------------------------------------------------------
  External References
 *---------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;

#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
extern uint32_t __STACK_SEAL;
#endif

extern __NO_RETURN void __PROGRAM_START(void);

/*---------------------------------------------------------------------------
  Internal References
 *---------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void);
__NO_RETURN void Default_Handler(void);
__NO_RETURN void Default_HF_Handler(void);
/*<! System Init function is declared here, implemented later */
void SystemInit(void);
/*---------------------------------------------------------------------------
  Hard Fault Handler
 *---------------------------------------------------------------------------*/
__NO_RETURN void Default_HF_Handler(void)
{
    while (1)
        ;
}

/*---------------------------------------------------------------------------
  Default Handler for Exceptions / Interrupts
 *---------------------------------------------------------------------------*/
__NO_RETURN void Default_Handler(void)
{
    while (1)
        ;
}

/*---------------------------------------------------------------------------
  Reset Handler called on controller reset
 *---------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void)
{
    __set_PSP(reinterpret_cast<uint32_t>(&__INITIAL_SP));

/* ToDo: Initialize stack limit register for Armv8-M Main Extension based processors*/
//    __set_MSP((uint32_t)(&__STACK_LIMIT));
//    __set_PSP((uint32_t)(&__STACK_LIMIT));

/* ToDo: Add stack sealing for Armv8-M based processors */
#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    __TZ_set_STACKSEAL_S((uint32_t *)(&__STACK_SEAL));
#endif

    SystemInit();      /* CMSIS System Initialization */
    __PROGRAM_START(); /* Enter PreMain (C library entry point) */
}

void SystemInit(void)
{

}
/*---------------------------------------------------------------------------
  Exception / Interrupt Handler Declarations
 *---------------------------------------------------------------------------*/
void NMI_Handler                        (void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler                  (void) __attribute__((weak, alias("Default_HF_Handler")));
/*   0                                                                                       */
/*   0                                                                                       */
/*   0                                                                                       */
/*   0                                                                                       */
/*   0                                                                                       */
/*   0                                                                                       */
/*   0                                                                                       */
void SVC_Handler                        (void) __attribute__((weak, alias("Default_Handler")));
/*   0                                                                                       */
/*   0                                                                                       */
void PendSV_Handler                     (void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler                    (void) __attribute__((weak, alias("Default_Handler")));
void WWDG_IRQHandler                    (void) __attribute__((weak, alias("Default_Handler")));
void PVD_IRQHandler                     (void) __attribute__((weak, alias("Default_Handler")));
void RTC_IRQHandler                     (void) __attribute__((weak, alias("Default_Handler")));
void FLASH_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void RCC_IRQHandler                     (void) __attribute__((weak, alias("Default_Handler")));
void EXTI0_1_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void EXTI2_3_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void EXTI4_15_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
/*   0                                                                                       */
void DMA1_Channel1_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel2_3_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel4_5_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void ADC1_IRQHandler                    (void) __attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_UP_TRG_COM_IRQHandler     (void) __attribute__((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void TIM1_TRG_COM_TIM17_IRQHandler      (void) __attribute__((weak, alias("Default_Handler")));
void TIM2_IRQHandler                    (void) __attribute__((weak, alias("Default_Handler")));
void TIM3_IRQHandler                    (void) __attribute__((weak, alias("Default_Handler")));
/*   0                                                                                       */
/*   0                                                                                       */
void TIM14_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
/*   0                                                                                       */
void TIM16_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void TIM17_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void I2C1_IRQHandler                    (void) __attribute__((weak, alias("Default_Handler")));
/*   0                                                                                       */
void SPI1_IRQHandler                    (void) __attribute__((weak, alias("Default_Handler")));
/*   0                                                                                       */
void USART1_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
/*   0                                                                                       */
/*   0                                                                                       */
/*   0                                                                                       */
/*   0                                                                                       */
#ifdef __cplusplus
}
#endif
/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table Definitions
 *----------------------------------------------------------------------------*/

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

/* ToDo: Add Cortex exception vectors according the used Cortex-Core */
extern const VECTOR_TABLE_Type __VECTOR_TABLE[48];
const VECTOR_TABLE_Type __VECTOR_TABLE[48] __VECTOR_TABLE_ATTRIBUTE =
{
    reinterpret_cast<VECTOR_TABLE_Type>(&__INITIAL_SP)           /* Initial Stack Pointer                     */,
    reinterpret_cast<VECTOR_TABLE_Type>(&Reset_Handler                      /* Reset Handler                             */),
    reinterpret_cast<VECTOR_TABLE_Type>(&NMI_Handler                                                                       ),
    reinterpret_cast<VECTOR_TABLE_Type>(&HardFault_Handler                                                                 ),
    reinterpret_cast<VECTOR_TABLE_Type>(0                                                                                  ),
    reinterpret_cast<VECTOR_TABLE_Type>(0                                                                                  ),
    reinterpret_cast<VECTOR_TABLE_Type>(0                                                                                  ),
    reinterpret_cast<VECTOR_TABLE_Type>(0                                                                                  ),
    reinterpret_cast<VECTOR_TABLE_Type>(0                                                                                  ),
    reinterpret_cast<VECTOR_TABLE_Type>(0                                                                                  ),
    reinterpret_cast<VECTOR_TABLE_Type>(0                                                                                  ),
    reinterpret_cast<VECTOR_TABLE_Type>(&SVC_Handler                                                                       ),
    reinterpret_cast<VECTOR_TABLE_Type>(0                                                                                  ),
    reinterpret_cast<VECTOR_TABLE_Type>(0                                                                                  ),
    reinterpret_cast<VECTOR_TABLE_Type>(&PendSV_Handler                                                                    ),
    reinterpret_cast<VECTOR_TABLE_Type>(&SysTick_Handler                                                                   ),
    reinterpret_cast<VECTOR_TABLE_Type>(&WWDG_IRQHandler                  /* Window WatchDog                             */),
    reinterpret_cast<VECTOR_TABLE_Type>(&PVD_IRQHandler                   /* PVD through EXTI Line detect                */),
    reinterpret_cast<VECTOR_TABLE_Type>(&RTC_IRQHandler                   /* RTC through the EXTI line                   */),
    reinterpret_cast<VECTOR_TABLE_Type>(&FLASH_IRQHandler                 /* FLASH                                       */),
    reinterpret_cast<VECTOR_TABLE_Type>(&RCC_IRQHandler                   /* RCC                                         */),
    reinterpret_cast<VECTOR_TABLE_Type>(&EXTI0_1_IRQHandler               /* EXTI Line 0 and 1                           */),
    reinterpret_cast<VECTOR_TABLE_Type>(&EXTI2_3_IRQHandler               /* EXTI Line 2 and 3                           */),
    reinterpret_cast<VECTOR_TABLE_Type>(&EXTI4_15_IRQHandler              /* EXTI Line 4 to 15                           */),
    reinterpret_cast<VECTOR_TABLE_Type>(0                                 /* Reserved                                    */),
    reinterpret_cast<VECTOR_TABLE_Type>(&DMA1_Channel1_IRQHandler         /* DMA1 Channel 1                              */),
    reinterpret_cast<VECTOR_TABLE_Type>(&DMA1_Channel2_3_IRQHandler       /* DMA1 Channel 2 and Channel 3                */),
    reinterpret_cast<VECTOR_TABLE_Type>(&DMA1_Channel4_5_IRQHandler       /* DMA1 Channel 4 and Channel 5                */),
    reinterpret_cast<VECTOR_TABLE_Type>(&ADC1_IRQHandler                  /* ADC1                                        */),
    reinterpret_cast<VECTOR_TABLE_Type>(&TIM1_BRK_UP_TRG_COM_IRQHandler   /* TIM1 Break, Update, Trigger and Commutation */),
    reinterpret_cast<VECTOR_TABLE_Type>(&TIM1_CC_IRQHandler               /* TIM1 Capture Compare                        */),
    reinterpret_cast<VECTOR_TABLE_Type>(&TIM2_IRQHandler                  /* TIM2                                        */),
    reinterpret_cast<VECTOR_TABLE_Type>(&TIM3_IRQHandler                  /* TIM3                                        */),
    reinterpret_cast<VECTOR_TABLE_Type>(0                                 /* Reserved                                    */),
    reinterpret_cast<VECTOR_TABLE_Type>(0                                 /* Reserved                                    */),
    reinterpret_cast<VECTOR_TABLE_Type>(&TIM14_IRQHandler                 /* TIM14                                       */),
    reinterpret_cast<VECTOR_TABLE_Type>(0                                 /* Reserved                                    */),
    reinterpret_cast<VECTOR_TABLE_Type>(&TIM16_IRQHandler                 /* TIM16                                       */),
    reinterpret_cast<VECTOR_TABLE_Type>(&TIM17_IRQHandler                 /* TIM17                                       */),
    reinterpret_cast<VECTOR_TABLE_Type>(&I2C1_IRQHandler                  /* I2C1                                        */),
    reinterpret_cast<VECTOR_TABLE_Type>(0                                 /* Reserved                                    */),
    reinterpret_cast<VECTOR_TABLE_Type>(&SPI1_IRQHandler                  /* SPI1                                        */),
    reinterpret_cast<VECTOR_TABLE_Type>(0                                 /* Reserved                                    */),
    reinterpret_cast<VECTOR_TABLE_Type>(&USART1_IRQHandler                /* USART1                                      */),
    reinterpret_cast<VECTOR_TABLE_Type>(0                                 /* Reserved                                    */),
    reinterpret_cast<VECTOR_TABLE_Type>(0                                 /* Reserved                                    */),
    reinterpret_cast<VECTOR_TABLE_Type>(0                                 /* Reserved                                    */),
    reinterpret_cast<VECTOR_TABLE_Type>(0                                 /* Reserved                                    */)
};
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#endif


#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic pop
#endif

