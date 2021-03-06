/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Bit_Operations>
 *       Module:  - Common
 *
 *  Description:  <Bit Macros>     
 *  
 *********************************************************************************************************************/
#ifndef <BIT_OPERATIONS_H>
#define <BIT_OPERATIONS_H>

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define SET_BIT(Var,BitNo) (Var|= (1<<BitNo))
#define CLR_BIT(Var,BitNo) (Var&= ~(1<<BitNo))
#define TOG_BIT(Var,BitNo) (Var^= (1<<BitNo))
#define GET_BIT(Var,BitNo) ((Var>>BitNo) & 1)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* BIT_OPERATIONS_H */

/**********************************************************************************************************************
 *  END OF FILE: Bit_Operations.h
 *********************************************************************************************************************/