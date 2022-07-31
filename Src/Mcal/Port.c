/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Platform_Types.h"
#include "Mcu_Hw.h"
#include "Port.h"
#include "Port_Cfg.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
static const uint32 Port_BaseAddress[6] = {
	GPIO_PORTA_APB_BASE_ADDRESS,
	GPIO_PORTB_APB_BASE_ADDRESS,
	GPIO_PORTC_APB_BASE_ADDRESS,
	GPIO_PORTD_APB_BASE_ADDRESS,
	GPIO_PORTE_APB_BASE_ADDRESS,
	GPIO_PORTF_APB_BASE_ADDRESS};

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Service name		: Port_Init
* \Syntax          	: void Port_Init( const Port_ConfigType* ConfigPtr )        
* \Description     	: Initializes the Port Driver module.                                                                  
* \Sync\Async      	: Synchronous                                               
* \Reentrancy      	: Non Reentrant                                             
* \Parameters (in) 	: ConfigPtr	->	Pointer to configuration set.
* \Parameters (out)	: None                                                      
* \Return value:   	: None 
*******************************************************************************/
void Port_Init(const Port_ConfigType *ConfigPtr)
{
    Port_PinType Temp_Pin;
	Port_PinDirectionType Temp_Dir;
	Port_PinModeType Temp_Mode;
	Port_PinOutputCurrentType Temp_Current;
	Port_PinInternalAttachType Temp_Attach;
	uint8 Port, Pin, Counter;

    for (Counter = 0; Counter < NUMBER_OF_ACTIVATED_CHANNELS; Counter++)
	{

		Temp_Pin = ConfigPtr[Counter].Pin;
		Temp_Dir = ConfigPtr[Counter].Dir;
		Temp_Mode = ConfigPtr[Counter].Mode;
		Temp_Current = ConfigPtr[Counter].OutputCurr;
		Temp_Attach = ConfigPtr[Counter].Attach;

        for(Counter=0;Counter<NUMBER_OF_ACTIVATED_CHANNELS;Counter++)
        {
            Temp_Pin = ConfigPtr[Counter].Pin;
		    Temp_Dir = ConfigPtr[Counter].Dir;
		    Temp_Mode = ConfigPtr[Counter].Mode;
		    Temp_Current = ConfigPtr[Counter].OutputCurr;
		    Temp_Attach = ConfigPtr[Counter].Attach;
            Port=Temp_Pin/8;
            Pin=Temp_Pin%8;

            HwAccess(Port_BaseAddress[Port] + GPIOLOCK_OFFSET) |= UNLOCK_KEY;		 // Unlock GPIO 
		    HwAccess(Port_BaseAddress[Port] + GPIOCR_OFFSET) |= ((uint8)(1 << Pin)); // Digital Enable GPIO
        }
        if (Temp_Dir == PORT_PIN_OUT)
        {
			HwAccess(Port_BaseAddress[Port] + GPIODIR_OFFSET) |= (1 << Pin);
        }
		else if (Temp_Dir == PORT_PIN_IN)
        {
			HwAccess(Port_BaseAddress[Port] + GPIODIR_OFFSET) &= (~(1 << Pin));
        }
        else
        {
            // Do nothing
        }

		if (Temp_Attach == PULLUP && Temp_Dir == PORT_PIN_IN)
        {
			HwAccess(Port_BaseAddress[Port] + GPIOPUR_OFFSET) |= (1 << Pin);
        }
		else if (Temp_Attach == PULLDOWN && Temp_Dir == PORT_PIN_IN)
        {
			HwAccess(Port_BaseAddress[Port] + GPIOPDR_OFFSET) |= (1 << Pin);
        }
		else if (Temp_Attach == OPENDRAIN && Temp_Dir == PORT_PIN_OUT)
        {
			HwAccess(Port_BaseAddress[Port] + GPIOODR_OFFSET) |= (1 << Pin);
        }
        else
        {
            // Do nothing
        }
		if (Temp_Current == CURRENT_2M)
        {
			HwAccess(Port_BaseAddress[Port] + GPIODR2R_OFFSET) |= (1 << Pin);
        }
		else if (Temp_Current == CURRENT_4M)
        {
			HwAccess(Port_BaseAddress[Port] + GPIODR4R_OFFSET) |= (1 << Pin);
        }
		else if (Temp_Current == CURRENT_8M)
        {
			HwAccess(Port_BaseAddress[Port] + GPIODR8R_OFFSET) |= (1 << Pin);
        }

		if (Temp_Mode == DIO)
		{

			HwAccess(Port_BaseAddress[Port] + GPIODEN_OFFSET) |= ((uint8)(1 << Pin)); // GPIO Digital Enable

			HwAccess(Port_BaseAddress[Port] + GPIOAFSEL_OFFSET) &= (~(1 << Pin));
		}

		else
		{

			HwAccess(Port_BaseAddress[Port] + GPIODEN_OFFSET) |= ((uint8)(1 << Pin)); // GPIO Digital Enable
			HwAccess(Port_BaseAddress[Port] + GPIOAFSEL_OFFSET) |= (1 << Pin);
			HwAccess(Port_BaseAddress[Port] + GPIOPCTL_OFFSET) |= ((Temp_Mode << (4 * Pin)));
		}
	}

}

/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/