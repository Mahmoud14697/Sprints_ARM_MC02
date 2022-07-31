/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <MicroController Hardware>
 *       Module:  -Common Files
 *
 *  Description:  <Hardware Adresses>     
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#define HwAccess(Address) (*((volatile uint32 *)(Address)))

/* preiphrals */

/* Interrupt APINT */

typedef struct
{
    uint32 VECTRESET : 1;
    uint32 VECTCLRACT : 1;
    uint32 SYSRESREQ : 1;
    uint32 : 5;
    uint32 PRIGROUP : 3;
    uint32 : 4;
    uint32 ENDIANESS : 1;
    uint32 VECTKEY : 16;
} APINT_BF;

typedef union
{
    uint32 R;
    APINT_BF B;
} APINT_TAG;

/* ----------------------------------------------------------------------------------------------------------------------------------------------*/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define CORTEX_M4_PERIPHERALS_BASE_ADDRESS 0xE000E000
#define CORTEX_M4_SYSTEM_CONTROL_BASE_ADDRESS 0x400FE000

#define NVIC_ENX_BASE_ADDRESS (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0x100)
#define NVIC_PRIX_BASE_ADDRESS (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0x400)

#define GPIO_PORTA_APB_BASE_ADDRESS 0x40004000
#define GPIO_PORTB_APB_BASE_ADDRESS 0x40005000
#define GPIO_PORTC_APB_BASE_ADDRESS 0x40006000
#define GPIO_PORTD_APB_BASE_ADDRESS 0x40007000
#define GPIO_PORTE_APB_BASE_ADDRESS 0x40024000
#define GPIO_PORTF_APB_BASE_ADDRESS 0x40025000

#define GPIO_PORTA_AHB_BASE_ADDRESS 0x40058000
#define GPIO_PORTB_AHB_BASE_ADDRESS 0x40059000
#define GPIO_PORTC_AHB_BASE_ADDRESS 0x4005A000
#define GPIO_PORTD_AHB_BASE_ADDRESS 0x4005B000
#define GPIO_PORTE_AHB_BASE_ADDRESS 0x4005C000
#define GPIO_PORTF_AHB_BASE_ADDRESS 0x4005D000

#define GPIOLOCK_OFFSET 0x520
#define GPIOCR_OFFSET 0x524
#define GPIODIR_OFFSET 0x400
#define GPIOPUR_OFFSET 0x510
#define GPIOPDR_OFFSET 0x514
#define GPIOODR_OFFSET 0x50C
#define GPIODR2R_OFFSET 0x500
#define GPIODR4R_OFFSET 0x504
#define GPIODR8R_OFFSET 0x508
#define GPIODEN_OFFSET 0x51C
#define GPIOAFSEL_OFFSET 0x420
#define GPIOPCTL_OFFSET 0x52C
#define GPIODATA_OFFSET 0x000


#define _16_32_BIT_TIMER_0_BASE_ADDRESS 0x40030000
#define _16_32_BIT_TIMER_1_BASE_ADDRESS 0x40031000
#define _16_32_BIT_TIMER_2_BASE_ADDRESS 0x40032000
#define _16_32_BIT_TIMER_3_BASE_ADDRESS 0x40033000
#define _16_32_BIT_TIMER_4_BASE_ADDRESS 0x40034000
#define _16_32_BIT_TIMER_5_BASE_ADDRESS 0x40035000
#define _32_64_BIT_WIDE_TIMER_0_BASE_ADDRESS 0x40036000
#define _32_64_BIT_WIDE_TIMER_1_BASE_ADDRESS 0x40037000
#define _32_64_BIT_WIDE_TIMER_2_BASE_ADDRESS 0x4004C000
#define _32_64_BIT_WIDE_TIMER_3_BASE_ADDRESS 0x4004D000
#define _32_64_BIT_WIDE_TIMER_4_BASE_ADDRESS 0x4004E000
#define _32_64_BIT_WIDE_TIMER_5_BASE_ADDRESS 0x4004F000


#define GPTMCFG_OFFSET 0x000
#define GPTMTAMR_OFFSET 0x004
#define GPTMTBMR_OFFSET 0x008
#define GPTMIMR_OFFSET 0x018
#define GPTMCTL_OFFSET 0x00C
#define GPTMTAILR_OFFSET 0x028
#define GPTMTAV_OFFSET 0x050
#define GPTMTBV_OFFSET 0x054
#define GPTMTAPV_OFFSET 0x064
#define GPTMTBPV_OFFSET 0x068


/* Preiphral addresses */

#define APINT (*((volatile APINT_TAG *)(CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xD0C)))


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

#endif /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
