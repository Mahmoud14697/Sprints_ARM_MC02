/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
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
#include "Mcu_Hw.h"
#include "Platform_Types.h"
#include "DIO.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
static const uint32 Port_APB_BaseAddress[6] = {
	GPIO_PORTA_APB_BASE_ADDRESS,
	GPIO_PORTB_APB_BASE_ADDRESS,
	GPIO_PORTC_APB_BASE_ADDRESS,
	GPIO_PORTD_APB_BASE_ADDRESS,
	GPIO_PORTE_APB_BASE_ADDRESS,
	GPIO_PORTF_APB_BASE_ADDRESS};

static const uint32 Port_AHB_BaseAddress[6] = {
GPIO_PORTA_AHB_BASE_ADDRESS,
GPIO_PORTB_AHB_BASE_ADDRESS,
GPIO_PORTC_AHB_BASE_ADDRESS,
GPIO_PORTD_AHB_BASE_ADDRESS,
GPIO_PORTE_AHB_BASE_ADDRESS,
GPIO_PORTF_AHB_BASE_ADDRESS
};

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
* \Syntax          : Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId )        
* \Description     : Returns the value of the specified DIO channel                                                                 
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId --> ID of DIO channel                     
* \Parameters (out): None                                                      
* \Return value:   : Dio_LevelType --> STD_HIGH The physical level of the corresponding Pin is STD_HIGH 
																	 -> STD_LOW  The physical level of the corresponding Pin is STD_LOW                             
*******************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{

	Dio_LevelType level;
	uint8 portPos, channelPos;
	portPos = ChannelId / 8;
	channelPos = ChannelId % 8;
	uint32 GPIO_DATA = Port_APB_BaseAddress[portPos] + GPIODATA_OFFSET + (4 * (1 << channelPos));
	level = ((HwAccess(GPIO_DATA) >> channelPos) & 1);
	return level;
}

/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId )        
* \Description     : set a level of a specified DIO channel.                                                                  
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId     --> ID of DIO channel
					 Level		   --> Value to be written                    
* \Parameters (out): None                                                      
* \Return value:   : None                                
*******************************************************************************/

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    uint8 portPos, channelPos;
	portPos = ChannelId / 8;
	channelPos = ChannelId % 8;
	uint32 GPIO_DATA = Port_APB_BaseAddress[portPos] + GPIODATA_OFFSET + (4 * (1 << channelPos));
	HwAccess(GPIO_DATA) = ((uint32)(Level << channelPos));
}



/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId )        
* \Description     : Returns the level of all channels of that port.                                                                  
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortId     	 -->	ID of DIO Port
* \Parameters (out): None                                                      
* \Return value:   : Dio_PortLevelType 	-->	Level of all channels of that port                                
*******************************************************************************/

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	Dio_PortLevelType portLevel;
	uint32 GPIO_DATA = Port_APB_BaseAddress[PortId] + GPIODATA_OFFSET + 0X3FC;
	portLevel = ((uint8)HwAccess(GPIO_DATA));
	return portLevel;
}

/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId )        
* \Description     : Service to set a value of all channels of the port.                                                                  
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortId	-->	ID of DIO Port
					 Level	-->	Value to be written
* \Parameters (out): None                                                      
* \Return value:   : None                                
*******************************************************************************/

void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
	uint32 GPIO_DATA = Port_APB_BaseAddress[PortId] + GPIODATA_OFFSET + GPIO_ShiftedLeft_2Bits;
	HwAccess(GPIO_DATA) = Level;
}

/******************************************************************************
* \Syntax          : Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId )        
* \Description     : Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel and return the level of the channel after flip.                                                                  
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId	-->	ID of DIO channel
* \Parameters (out): None                                                      
* \Return value:   : Dio_LevelType	-->	STD_high: The physical level of the corresponding Pin is STD_HIGH.
									-->	STD_low:  The physical level of the corresponding Pin is STD_LOW.                                
*******************************************************************************/

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{

	if (Dio_ReadChannel(ChannelId) == STD_low)
		Dio_WriteChannel(ChannelId, STD_high);
	else
		Dio_WriteChannel(ChannelId, STD_low);

	return Dio_ReadChannel(ChannelId);
}

/**********************************************************************************************************************
 *  END OF FILE: DIO.c
 *********************************************************************************************************************/