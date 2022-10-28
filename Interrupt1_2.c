/* ###################################################################
**     Filename    : Events.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-27, 16:29, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MKL25Z128LK4]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMIINT(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  EInt2_OnInterrupt (module Events)
**
**     Component   :  EInt2 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void EInt2_OnInterrupt(void)
{
  /* Write your code here ... */
	int i,j;
	  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	 // PE_low_level_init();
	  /*** End of Processor Expert internal initialization.                    ***/

	  /* Write your code here */

                    unsigned char k,n;
	  		  	  	k=0x80;
		            for(i=0;i<=7;i++)
	  		      	{
	  		      		n=0x00^k;
	  		      		Bits2_PutVal(~n);
	  		      		k=k>>1;
	  		      		for(j=0;j<0x7ffff;j++);
	  		      		
	  		      	}
}

/*
** ===================================================================
**     Event       :  EInt1_OnInterrupt (module Events)
**
**     Component   :  EInt1 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void EInt1_OnInterrupt(void)
{
  /* Write your code here ... */
	int i,j;
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  //PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */

                        unsigned char k,n;
		                k=0x80;
		  		      	for(i=0;i<=7;i++)
		  		      	{
		  		      		n=0x00^k;
		  		      		Bits1_PutVal(n);
		  		      		k=k>>1;
		  		      		for(j=0;j<0x7ffff;j++);
		  		      		
		  		      	}
}

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

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
