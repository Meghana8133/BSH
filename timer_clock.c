/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-31, 14:26, # CodeGen: 0
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
#include "TI1.h"
#include "TimerIntLdd1.h"
#include "TU1.h"
#include "Bits1.h"
#include "BitsIoLdd1.h"
#include "RS.h"
#include "BitIoLdd1.h"
#include "RW.h"
#include "BitIoLdd2.h"
#include "EN.h"
#include "BitIoLdd3.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
int ss=0,tens, units,MM=0,HH=0;
void LCD_Delay(unsigned char ms)
{
      unsigned char n;
      int i;
      for(n=0;n<ms;n++)
     	for(i=0;i<0x7fff;i++);
      
}
void LCD_command(unsigned char command)
{
	  Bits1_PutVal(command);
	  RS_PutVal(0);
	  RW_PutVal(0);
	  EN_PutVal(1);
	  LCD_Delay(1);
	  EN_PutVal(0);
}
void LCD_Data(unsigned char data)
{
	  Bits1_PutVal(data);
      RS_PutVal(1);
      RW_PutVal(0);
      EN_PutVal(1);
      LCD_Delay(1);
      EN_PutVal(0);    	
} 
void LCD_init()
{
	LCD_command(0x38);
	LCD_command(0x01);
	LCD_command(0x0F);
	LCD_command(0x06);
	LCD_command(0x80);
	LCD_Delay(1);
}
void me_char(unsigned int a)
{
	tens=a/10;
	units=a%10;
}
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
 LCD_init();
 char set;
  /* Write your code here */
while(1)
{   
	  me_char(HH);
	  LCD_command(0x80); 
	  LCD_Data(tens+48);
	  LCD_command(0x81);
	  LCD_Data(units+48);
	  LCD_command(0x82);
	  LCD_Data(':');
	  
	  LCD_command(0x83);
	  me_char(MM);
	  LCD_Data(tens+48);
	  LCD_command(0x84);
	  LCD_Data(units+48);
	  LCD_command(0x85);
	  LCD_Data(':');
	  
	  LCD_command(0x86);
	  me_char(ss);
	  LCD_Data(tens+48);
	  LCD_command(0x87);
	  LCD_Data(units+48);
}
  /* For example: for(;;) { } */

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

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

//up above code is for lcd data







/* ###################################################################
**     Filename    : Events.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-31, 14:26, # CodeGen: 0
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
extern int ss,MM,HH;
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
**     Event       :  TI1_OnInterrupt (module Events)
**
**     Component   :  TI1 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TI1_OnInterrupt(void)
{
  /* Write your code here ... */
	ss++;
	 if(ss==60)
			  {
				  ss=0;
				  MM=MM+1;
			  }
			  if(MM==60)
			  {
				  MM=0;
				  HH=HH+1;
			  }
			  if(MM==60)
			  {
				  HH=0;
			  }
}

	
	
	


/* END Events */

#ifdef __cplusplus
 /* extern "C" */
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


// up above code is for timer to work
