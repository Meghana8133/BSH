/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-20, 11:22, # CodeGen: 0
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
#include "RS.h"
#include "BitIoLdd1.h"
#include "RW.h"
#include "BitIoLdd2.h"
#include "EN.h"
#include "BitIoLdd3.h"
#include "Column.h"
#include "BitsIoLdd2.h"
#include "Row.h"
#include "BitsIoLdd3.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
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
void keypad()
{
	int i,r,c;
	Row_SetDir(1);
	Column_SetDir(1);
	Row_PutVal(0x0);
	Column_PutVal(0xf);
	Column_SetDir(0);
	c=Column_GetVal();
	
	Row_SetDir(1);
	Column_SetDir(1);
	Row_PutVal(0xf);
	Column_PutVal(0x0);
	Row_SetDir(0);
	r=Row_GetVal();
	
	LCD_command(0x80);
	if(c==0xe)
	{
		LCD_Data('1');
	}
	else if(c==0xd)
	{
		LCD_Data('2');
	}
	else if(c==0xb)
	{
	    LCD_Data('3');
	}
	else if(c==0x7)
	{
	    LCD_Data('4');
	}
	LCD_command(0xc0);
	if(r==0xe)
	{
		LCD_Data('1');
	}
	else if(r==0xd)
	{
	    LCD_Data('2');
	}
	else if(r==0xb)
	{
	    LCD_Data('3');
	}
	else if(r==0x7)
	{
	    LCD_Data('4');
	}		
}

int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  LCD_init();
  	while(1)
  	{
  		keypad();
  	}
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
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
