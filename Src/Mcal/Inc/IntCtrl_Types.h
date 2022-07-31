/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Interrupt Contol Types>
 *       Module:  - Mcal
 *
 *  Description:  <Types of Interrupt Control>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Platform_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* Exceptions types*/
typedef enum{
	
/*Reserved*/
	
Exception_Reset                         = -14	,	
	
Exception_Non_Maskable_Interrupt        = -13   ,
	
Exception_Hard_Fault                    = -12   ,
	
Exception_Memory_Management             = -11   ,
	
Exception_Bus_Fault                     = -10   ,
	
Exception_Usage_Fault                   = -9    ,
	
/*Reserved*/

Exception_SVCall                        = -4 	,
	
Exception_Debug_Monitor                 = -3	,
	
Exception_PendSV                        = -2	,
	
Exception_SysTick                       = -1	, 	


}Processor_ExceptionsType;


/* Interrupt types*/

typedef enum{
	
Interrupt_GPIO_Port_A                               = 0  	,
Interrupt_GPIO_Port_B                                       ,
Interrupt_GPIO_Port_C                                       ,
Interrupt_GPIO_Port_D                                       ,
Interrupt_GPIO_Port_E                                       ,
	
Interrupt_Uart_0                                    = 5  	,
Interrupt_Uart_1                                            ,
	
Interrupt_SSI0                                      = 7  	,
	
Interrupt_I2C0                                      = 8	    ,
	
Interrupt_PWM0_Fault                                = 9 	,
Interrupt_PWM0_Generator_0      				            ,
Interrupt_PWM0_Generator_1						            ,
Interrupt_PWM0_Generator_2						            ,
	
Interrupt_QEI0                			            = 13	,
	
Interrupt_ADC0_Sequence_0			            	= 14    ,
Interrupt_ADC0_Sequence_1           						,
Interrupt_ADC0_Sequence_2						            ,
Interrupt_ADC0_Sequence_3				            		,

Interrupt_Watchdog_Timers_0_and_1 		            = 18    ,

Interrupt_16_32_Bit_Timer_0A			            = 19    ,	
Interrupt_16_32_Bit_Timer_0B            					,
Interrupt_16_32_Bit_Timer_1A				            	,
Interrupt_16_32_Bit_Timer_1B		            			,
Interrupt_16_32_Bit_Timer_2A			            		,
Interrupt_16_32_Bit_Timer_2B            					,

Interrupt_Analog_Comparator_0       	            = 25    ,
Interrupt_Analog_Comparator_1           					,

/*Reserved*/									

Interrupt_System_Control			            	= 28    ,

Interrupt_Flash_Memory_Control_And_EEPROM_Control 	= 29 	,

Interrupt_GPIO_Port_F     							= 30    ,

/*Reserved*/

Interrupt_UART2 									= 33 	,

Interrupt_SSI1 										= 34 	,

Interrupt_16_32_Bit_Timer_3A 						= 35 	,
Interrupt_16_32_Bit_Timer_3B 								,

Interrupt_I2C1										= 37 	,

Interrupt_QEI1 										= 38 	,

Interrupt_CAN0 										= 39 	,
Interrupt_CAN1 												,

/*Reserved*/									

Interrupt_Hibernation_Module  						= 43	,

Interrupt_USB 										= 44	,

Interrupt_PWM_Generator 							= 45	,

Interrupt_uDMA_Software								= 46 	,
Interrupt_uDMA_Error										,

Interrupt_ADC1_Sequence_0							= 48    ,
Interrupt_ADC1_Sequence_1									,
Interrupt_ADC1_Sequence_2									,
Interrupt_ADC1_Sequence_3									,

/*Reserved*/									

Interrupt_SSI2										= 57    ,
Interrupt_SSI3												,

Interrupt_UART3										= 59	,
Interrupt_UART4												,
Interrupt_UART5												,
Interrupt_UART6												,
Interrupt_UART7												,

/*Reserved*/	

Interrupt_I2C2										= 68	,
Interrupt_I2C3												,

Interrupt_16_32_Bit_Timer_4A						= 70	,
Interrupt_16_32_Bit_Timer_4B								,

/*Reserved*/	

Interrupt_16_32_Bit_Timer_5A						= 92 	,
Interrupt_16_32_Bit_Timer_5B								,
Interrupt_32_64_Bit_Timer_0A								,
Interrupt_32_64_Bit_Timer_0B								,
Interrupt_32_64_Bit_Timer_1A								,
Interrupt_32_64_Bit_Timer_1B								,
Interrupt_32_64_Bit_Timer_2A								,
Interrupt_32_64_Bit_Timer_2B								,
Interrupt_32_64_Bit_Timer_3A								,
Interrupt_32_64_Bit_Timer_3B								,
Interrupt_32_64_Bit_Timer_4A								,
Interrupt_32_64_Bit_Timer_4B								,
Interrupt_32_64_Bit_Timer_5A								,
Interrupt_32_64_Bit_Timer_5B								,

Interrupt_System_Exception_Imprecise 				= 106   ,

/*Reserved*/	

Interrupt_PWM1_Generator_0							= 134   ,
Interrupt_PWM1_Generator_1									,
Interrupt_PWM1_Generator_2								    ,
Interrupt_PWM1_Generator_3									,
Interrupt_PWM1_Fault																						

}Nvic_InterruptType;	

typedef struct{
	
Nvic_InterruptType	Interrupt_Number;
uint8				Group_Priority;
uint8				SubGroup_Priority;
	
}Interrupt_CfgType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/