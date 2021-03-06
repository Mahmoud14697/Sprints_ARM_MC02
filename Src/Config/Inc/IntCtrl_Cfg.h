/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Cfg.h
 *       Module:  - IntCtrl Module - Config
 *
 *  Description:  <Configuration of Interrupt Contol module>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_CFG_H
#define INTCTRL_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "IntCtrl.h"



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*
*	please choose form the followings
*	GROUPING_SYSTEM_XXX : [0-7] Groups , [ 0 ]subgroups 
*	GROUPING_SYSTEM_XXY : [0-3] Groups , [0-1]subgroups	
*	GROUPING_SYSTEM_XYY : [0-1] Groups , [0-3]subgroups	
*	GROUPING_SYSTEM_YYY : [ 0 ] Groups , [0-7]subgroups	
*/

#define GROUPING_SYSTEM   GROUPING_SYSTEM_XXX

#define NUM_OF_ACTIVATED_GROUPS 3


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

extern const Interrupt_CfgType Interrupt_Groups[NUM_OF_ACTIVATED_GROUPS];


#endif  /* INTCTRL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/
