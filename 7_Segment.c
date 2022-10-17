/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-17, 14:59, # CodeGen: 0
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
#include "Bits1.h"
#include "BitsIoLdd1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */

  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
	int i,j,n;
	
	void SS(n)
	{
		switch(n){
			case 0:
					if(n==0)
					Bits1_PutVal(0x3F);
					break;
			case 1:
					if(n==1)
					Bits1_PutVal(0x06);
			break;
			case 2:
					if(n==2)
					Bits1_PutVal(0x5B);
						break;
			case 3:
					if(n==3)
					Bits1_PutVal(0x4F);
						break;
			case 4:
					if(n==4)
					Bits1_PutVal(0x66);
					 break;
			case 5:
					if(n==5)
					Bits1_PutVal(0x6D);
					break;
			case 6:
					if(n==6)
					Bits1_PutVal(0x7C);
					break;
			case 7:
					if(n==7)
					Bits1_PutVal(0x07);
					break;
					
			case 8:
					if(n==8)
					Bits1_PutVal(0x7F);
					break;
								
			case 9:
					if(n==9)
					Bits1_PutVal(0x67);
					break;
								
			case 10:
					if(n==0x0a)
					Bits1_PutVal(0x77);
					break;
								
			case 11:
					if(n==0x0B)
					Bits1_PutVal(0x7F);
					break;
					
			case 12:
					if(n==0x0c)
					Bits1_PutVal(0x39);
					break;
										
			case 13:
					if(n==0x0d)
					Bits1_PutVal(0x3F);
					break;
										
			case 14:
												
					if(n==0x0e)
					Bits1_PutVal(0x79);
					break;
										
			case 15:
					if(n==0x0f)
					Bits1_PutVal(0x71);
					break;
			
				 
		 	
	}
}
	int main(void)
	/*lint -restore Enable MISRA rule (6.3) checking. */
	{
	  /* Write your local variable definition here */

	  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	  PE_low_level_init();
	  while(1)
	  {
		  for(i=0;i<16;i++)
		  {
			  SS(i);
			  for(j=0;j<0x7ffff;j++);
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
