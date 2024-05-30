#ifdef __cplusplus
extern "C" {
#endif
#include "vectors_llvm.h"
#include "system_ARMCM0.h"
#include "cmsis_compiler.h"

/******************************************************************************
 * @file     startup_<Device>.c
 * @brief    CMSIS-Core(M) Device Startup File for
 *           Device <Device>
 * @version  V1.0.0
 * @date     20. January 2021
 ******************************************************************************/
/*
 * Copyright (c) 2009-2021 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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

void SystemInit(void);
/* ToDo: Add Cortex exception handler according the used Cortex-Core */
/*---------------------------------------------------------------------------
  Exception / Interrupt Handler
 *---------------------------------------------------------------------------*/
void NMI_Handler                        (void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler                  (void) __attribute__((weak));
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

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

/* ToDo: Add Cortex exception vectors according the used Cortex-Core */
extern const VECTOR_TABLE_Type __VECTOR_TABLE[48];
const VECTOR_TABLE_Type __VECTOR_TABLE[48] __VECTOR_TABLE_ATTRIBUTE = {
    (VECTOR_TABLE_Type)(&__INITIAL_SP                       /* Initial Stack Pointer                     */),
    (VECTOR_TABLE_Type)(&Reset_Handler                      /* Reset Handler                             */),
    (VECTOR_TABLE_Type)(&NMI_Handler                                                                       ),
    (VECTOR_TABLE_Type)(&HardFault_Handler                                                                 ),
    (VECTOR_TABLE_Type)(0                                                                                  ),
    (VECTOR_TABLE_Type)(0                                                                                  ),
    (VECTOR_TABLE_Type)(0                                                                                  ),
    (VECTOR_TABLE_Type)(0                                                                                  ),
    (VECTOR_TABLE_Type)(0                                                                                  ),
    (VECTOR_TABLE_Type)(0                                                                                  ),
    (VECTOR_TABLE_Type)(0                                                                                  ),
    (VECTOR_TABLE_Type)(&SVC_Handler                                                                       ),
    (VECTOR_TABLE_Type)(0                                                                                  ),
    (VECTOR_TABLE_Type)(0                                                                                  ),
    (VECTOR_TABLE_Type)(&PendSV_Handler                                                                    ),
    (VECTOR_TABLE_Type)(&SysTick_Handler                                                                   ),
    (VECTOR_TABLE_Type)(&WWDG_IRQHandler                  /* Window WatchDog                             */),
    (VECTOR_TABLE_Type)(&PVD_IRQHandler                   /* PVD through EXTI Line detect                */),
    (VECTOR_TABLE_Type)(&RTC_IRQHandler                   /* RTC through the EXTI line                   */),
    (VECTOR_TABLE_Type)(&FLASH_IRQHandler                 /* FLASH                                       */),
    (VECTOR_TABLE_Type)(&RCC_IRQHandler                   /* RCC                                         */),
    (VECTOR_TABLE_Type)(&EXTI0_1_IRQHandler               /* EXTI Line 0 and 1                           */),
    (VECTOR_TABLE_Type)(&EXTI2_3_IRQHandler               /* EXTI Line 2 and 3                           */),
    (VECTOR_TABLE_Type)(&EXTI4_15_IRQHandler              /* EXTI Line 4 to 15                           */),
    (VECTOR_TABLE_Type)(0                                 /* Reserved                                    */),
    (VECTOR_TABLE_Type)(&DMA1_Channel1_IRQHandler         /* DMA1 Channel 1                              */),
    (VECTOR_TABLE_Type)(&DMA1_Channel2_3_IRQHandler       /* DMA1 Channel 2 and Channel 3                */),
    (VECTOR_TABLE_Type)(&DMA1_Channel4_5_IRQHandler       /* DMA1 Channel 4 and Channel 5                */),
    (VECTOR_TABLE_Type)(&ADC1_IRQHandler                  /* ADC1                                        */),
    (VECTOR_TABLE_Type)(&TIM1_BRK_UP_TRG_COM_IRQHandler   /* TIM1 Break, Update, Trigger and Commutation */),
    (VECTOR_TABLE_Type)(&TIM1_CC_IRQHandler               /* TIM1 Capture Compare                        */),
    (VECTOR_TABLE_Type)(&TIM2_IRQHandler                  /* TIM2                                        */),
    (VECTOR_TABLE_Type)(&TIM3_IRQHandler                  /* TIM3                                        */),
    (VECTOR_TABLE_Type)(0                                 /* Reserved                                    */),
    (VECTOR_TABLE_Type)(0                                 /* Reserved                                    */),
    (VECTOR_TABLE_Type)(&TIM14_IRQHandler                 /* TIM14                                       */),
    (VECTOR_TABLE_Type)(0                                 /* Reserved                                    */),
    (VECTOR_TABLE_Type)(&TIM16_IRQHandler                 /* TIM16                                       */),
    (VECTOR_TABLE_Type)(&TIM17_IRQHandler                 /* TIM17                                       */),
    (VECTOR_TABLE_Type)(&I2C1_IRQHandler                  /* I2C1                                        */),
    (VECTOR_TABLE_Type)(0                                 /* Reserved                                    */),
    (VECTOR_TABLE_Type)(&SPI1_IRQHandler                  /* SPI1                                        */),
    (VECTOR_TABLE_Type)(0                                 /* Reserved                                    */),
    (VECTOR_TABLE_Type)(&USART1_IRQHandler                /* USART1                                      */),
    (VECTOR_TABLE_Type)(0                                 /* Reserved                                    */),
    (VECTOR_TABLE_Type)(0                                 /* Reserved                                    */),
    (VECTOR_TABLE_Type)(0                                 /* Reserved                                    */),
    (VECTOR_TABLE_Type)(0                                 /* Reserved                                    */)
};
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

/*---------------------------------------------------------------------------
  Reset Handler called on controller reset
 *---------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void)
{
    __set_PSP((uint32_t)(&__INITIAL_SP));

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

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#endif

/*---------------------------------------------------------------------------
  Hard Fault Handler
 *---------------------------------------------------------------------------*/
void HardFault_Handler(void)
{
    while (1)
        ;
}

/*---------------------------------------------------------------------------
  Default Handler for Exceptions / Interrupts
 *---------------------------------------------------------------------------*/
void Default_Handler(void)
{
    while (1)
        ;
}

void SystemInit(void)
{

}
#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic pop
#endif
#ifdef __cplusplus
}
#endif