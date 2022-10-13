/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-12, 11:50, # CodeGen: 0
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

/*lint -restore Enable MISRA rule (6.3) checking. */

  /* Write your local variable definition here */
	long int i;
	int j,k,n;
	
	
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/

  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  

    
   
    	void R_R()
    	{
    		k=0x01;
    		for(j=0;j<=n;j++)
    		{ 		
    		   Bits1_PutVal(k^0x0F);
    		   for(i=0;i<=0x7ffff;i++);
    		   k=k<<1;
    		}
    	}
    	void R_L()
    	{        
    	    for(j=0;j<=n;j++)
    		{ 		
    	    	Bits1_PutVal(k^0x0F);
    			for(i=0;i<=0x7ffff;i++);
    			k=k>>1;
    		}
    	}
    		        
    int main(void)
    {
    	PE_low_level_init();
     n=0; 
    while(1)
    	{	
    		for(n=7;n>=0;n--)
    		{
    			R_R();
        		R_L();
    		}
        }
     }
    
    
 
  /* For example: for(;;) { } */

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
