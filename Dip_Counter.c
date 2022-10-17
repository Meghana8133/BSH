/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-14, 09:27, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file ProcessorExpert.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup ProcessorExpert_module ProcessorExpert module documentation
**  @{
*/         
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Bit1.h"
#include "BitIoLdd1.h"
#include "Bits1.h"
#include "BitsIoLdd1.h"
#include "Bits2.h"
#include "BitsIoLdd2.h"
#include "Bit2.h"
#include "BitIoLdd2.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */

/*lint -restore Enable MISRA rule (6.3) checking. */

  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  
  /*** End of Processor Expert internal initialization.                    ***/
 
  /* Write your code here */
  /* For example: for(;;) { } */
long int n,i,a;
  void up(n)
    {
  	  if(Bit1_GetVal()==0)
  	  {
  		 n=n^0x0F;
  		 n=n+0x01;
  		 n=n^0x0F;
  		 Bits1_PutVal(n);
  		 a=n;
  		for(i=0;i<0x7ffff;i++);
  	   }
  	  }

  void down(n)
  {
	  if(Bit2_GetVal()==0)
	  {
		 n=n^0x0F;
		 n=n-0x01;
		 n=n^0x0F;
		 Bits1_PutVal(n);
		 a=n;
		for(i=0;i<0x7ffff;i++);
	   }
	  }

 int main(void)
  {
	 PE_low_level_init();
	  //a=Bits2_GetVal();
	  //Bits1_PutVal(a);
	 a=Bits2_GetVal();
	Bits1_PutVal(a);
	  while(1)
	  {
		 
		  if(Bit1_GetVal()==0)
		  {
			  up(a);
		  }
		  if(Bit2_GetVal()==0)
		  {
			  down(a);
			  
		  }
		
	  }
  }

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
 /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END ProcessorExpert */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.08]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
