/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Platform_Types.h"
#include "IntCtrl.h"
#include "Std_Types.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
extern const Interrupt_CfgType  Interrupt_Groups[];

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
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void)
{
uint8 Counter , Group_Temp , SubGroup_Temp , Interrupt_Number_Temp ,Grouping_Field	;
uint32 PriRegOffset	,PriBitOffset , EnRegOffset ,EnBitOffset;
	
APINT.B.VECTKEY=APINT_VECTKEY; 					 // Field Guard
APINT.B.ENDIANESS=STD_low;					    //Little-Endian Mode
	
	
APINT.B.PRIGROUP = GROUPING_SYSTEM;      //The Split Of Group Priority From Subpriority
	
for(Counter=0 ;Counter < NUM_OF_ACTIVATED_GROUPS;Counter++){
	
Interrupt_Number_Temp = Interrupt_Groups[Counter].Interrupt_Number;	
Group_Temp = Interrupt_Groups[Counter].Group_Priority;
SubGroup_Temp =	Interrupt_Groups[Counter].SubGroup_Priority;
	
// NVIC EN REG 
	
EnRegOffset = (Interrupt_Number_Temp/32)*4;
EnBitOffset = Interrupt_Number_Temp%32;
	
(*((volatile uint32*)(NVIC_ENX_BASE_ADDRESS + EnRegOffset  )))|= (1 << EnBitOffset);
	
if ( GROUPING_SYSTEM == GROUPING_SYSTEM_XXX)
	{
	Grouping_Field=Group_Temp ;
    }
else if ( GROUPING_SYSTEM == GROUPING_SYSTEM_XXY)
	{
	Grouping_Field=(((Group_Temp<<1)&(0x6))|((SubGroup_Temp)&(0x1)));
    }
else if ( GROUPING_SYSTEM == GROUPING_SYSTEM_XYY)
	{
	Grouping_Field=(((Group_Temp<<2)&(0x4))|((SubGroup_Temp)&(0x3)));	
    }
else if ( GROUPING_SYSTEM == GROUPING_SYSTEM_YYY)
	{
	Grouping_Field= SubGroup_Temp ;
    }
else
    {
    // Do Nothing
    }
// NVIC PRI REG 

PriRegOffset = (Interrupt_Number_Temp/4)*4;
PriBitOffset = 5 + (8 * (Interrupt_Number_Temp%4));
(*((volatile uint32*)(NVIC_PRIX_BASE_ADDRESS + PriRegOffset  ))) |= ((uint32)(Grouping_Field << PriBitOffset));

}
	
}
/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
