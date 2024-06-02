/**************************************************************************//**
 * @file      stm32f031k6.h
 * @brief    CMSIS-Core(M) stm32f031k6 Header File for stm32f031k6 <stm32f031k6>
 *
 * @version  V1.0.0
 * @date     18. July 2023
 ******************************************************************************/

#pragma once

/**
  \brief Exception / Interrupt Handler Function Prototype
*/
//typedef void(*VECTOR_TABLE_Type)(void);
using VECTOR_TABLE_Type = void (*)();

/* ========================================================================= */
/* ============           Interrupt Number Definition           ============ */
/* ========================================================================= */

typedef enum IRQn
{
/* ================     Cortex-M Core Exception Numbers     ================ */

/* Cortex exception numbers according the used Cortex-Core */
    Reset_IRQn                  = -15,  /*  1 Reset Vector invoked on Power up and warm reset */
    NonMaskableInt_IRQn         = -14,  /*  2 Non maskable Interrupt cannot be stopped or preempted */
    HardFault_IRQn              = -13,  /*  3 Hard Fault all classes of Fault */
    MemoryManagement_IRQn       = -12,  /*  4 Memory Management MPU mismatch, including Access Violation and No Match */
    BusFault_IRQn               = -11,  /*  5 Bus Fault Pre-Fetch-, Memory Access, other address/memory Fault */
    UsageFault_IRQn             = -10,  /*  6 Usage Fault i.e. Undef Instruction, Illegal State Transition */
    SecureFault_IRQn            =  -9,  /*  7 Secure Fault Interrupt */
    SVCall_IRQn                 =  -5,  /* 11 System Service Call via SVC instruction */
    DebugMonitor_IRQn           =  -4,  /* 12 Debug Monitor */
    PendSV_IRQn                 =  -2,  /* 14 Pendable request for system service */
    SysTick_IRQn                =  -1,  /* 15 System Tick Timer */
/* ================        <Device> Interrupt Numbers       ================ */
    WWDG_IRQn                   =   0,
    PVD_IRQn                    =   1,
    RTC_IRQn                    =   2,
    FLASH_IRQn                  =   3,
    RCC_IRQn                    =   4,
    EXTI0_1_IRQn                =   5,
    EXTI2_3_IRQn                =   6,
    EXTI4_15_IRQn               =   7,
    /* unused                       8, */
    DMA1_Channel1_IRQn          =   9,
    DMA1_Channel2_3_IRQn        =  10,
    DMA1_Channel4_5_IRQn        =  11,
    ADC1_IRQn                   =  12,
    TIM1_BRK_UP_TRG_COM_IRQn    =  13,
    TIM1_CC_IRQn                =  14,
    TIM2_IRQn                   =  15,
    TIM3_IRQn                   =  16,
    /* unused                      17, */
    /* unused                      18, */
    TIM14_IRQn                  =  19,
    /* unused                      20, */
    TIM16_IRQn                  =  21,
    TIM17_IRQn                  =  22,
    I2C1_IRQn                   =  23,
    /* unused                      24, */
    SPI1_IRQn                   =  25,
    /* unused                   =  26, */
    /* unused                   =  27, */
    /* unused                   =  28, */
    /* unused                   =  29 */
    MAX_IRQn                    =  30
} IRQn_Type;


#ifdef __cplusplus
    extern "C" {
#endif

/**
  \brief System Clock Frequency (Core Clock)
*/
extern uint32_t SystemCoreClock;

/**
  \brief Setup the microcontroller system.

   Initialize the System and update the SystemCoreClock variable.
 */
extern void SystemInit (void);


/**
  \brief  Update SystemCoreClock variable.

   Updates the SystemCoreClock with current core Clock retrieved from cpu registers.
 */
extern void SystemCoreClockUpdate (void);



/* ========================================================================= */
/* ============      Processor and Core Peripheral Section      ============ */
/* ========================================================================= */

/* ================ Start of section using anonymous unions ================ */
#if   defined (__CC_ARM)
    #pragma push
    #pragma anon_unions
#elif defined (__ICCARM__)
    #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wc11-extensions"
    #pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined (__GNUC__)
    /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
    /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
    #pragma warning 586
#elif defined (__CSMC__)
    /* anonymous unions are enabled by default */
#else
    #warning Not supported compiler type
#endif


/* --------  Configuration of Core Peripherals  ----------------------------------- */
/* set the defines according your Device */
/* Tdefine the correct core revision
         valid CMSIS core revision macro names are:
           __CM0_REV, __CM0PLUS_REV, __CM1_REV, __CM3_REV, __CM4_REV, __CM7_REV
           __CM23_REV, __CM33_REV, __CM35P_REV, __CM55_REV
           __SC000_REV, __SC300_REV */
#define __CM0_REV               0x0201U  /* Core Revision r2p1 */
/* define the correct core features for the <Device> */
#define __Vendor_SysTickConfig   0U       /* Set to 1 if different SysTick Config is used */
#define __NVIC_PRIO_BITS        3U       /* Number of Bits used for Priority Levels */
#define __VTOR_PRESENT          1U       /* Set to 1 if VTOR is present */
#define __MPU_PRESENT           0U       /* Set to 1 if MPU is present */
#define __FPU_PRESENT           0U       /* Set to 1 if FPU is present */
#define __FPU_DP                0U       /* Set to 1 if FPU is double precision FPU (default is single precision FPU) */
#define __DSP_PRESENT           0U       /* Set to 1 if DSP extension are present */
#define __SAUREGION_PRESENT     0U       /* Set to 1 if SAU regions are present */
#define __PMU_PRESENT           0U       /* Set to 1 if PMU is present */
#define __PMU_NUM_EVENTCNT      8U       /* Set number of PMU Event Counters */
#define __ICACHE_PRESENT        0U       /* Set to 1 if I-Cache is present */
#define __DCACHE_PRESENT        0U       /* Set to 1 if D-Cache is present */
#define __DTCM_PRESENT          0U       /* Set to 1 if DTCM is present */


/* include the CMSIS core header file according your device.
         valid CMSIS core header files are:
           core_cm0.h, core_cm0plus.h, core_cm1.h, core_cm3.h, core_cm4.h, core_cm7.h
           core_cm23.h, core_cm33.h, core_cm35p.h, core_cm55.h
           core_sc000.h, core_sc300.h */
#include <core_cm0.h>                           /* Processor and core peripherals */

/* There is no device header file, it's part of k_devices */
/* --------  End of section using anonymous unions and disabling warnings  -------- */
#if   defined (__CC_ARM)
    #pragma pop
#elif defined (__ICCARM__)
    /* leave anonymous unions enabled */
#elif (defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
    #pragma clang diagnostic pop
#elif defined (__GNUC__)
    /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
    /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
    #pragma warning restore
#elif defined (__CSMC__)
    /* anonymous unions are enabled by default */
#else
    #warning Not supported compiler type
#endif


#ifdef __cplusplus
}
#endif
