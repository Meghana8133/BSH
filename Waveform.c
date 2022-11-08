/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-11-04, 14:10, # CodeGen: 0
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
#include "FRTOS1.h"
#include "MCUC1.h"
#include "UTIL1.h"
#include "UTIL2.h"
#include "Bits1.h"
#include "BitsIoLdd1.h"
#include "Bits2.h"
#include "BitsIoLdd2.h"
#include "anode.h"
#include "BitsIoLdd3.h"
#include "cathode.h"
#include "BitsIoLdd4.h"
#include "CsIO1.h"
#include "IO1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
void task_1();
void task_2();
void task_3();

unsigned char a[]={0x3f,0x06,0x5b,0x4f,0x66};
int l;
/* User includes (#include below this line is not maintained by Processor Expert) */
void task_1()
{
	/*int j,l;
	
                char i[]={0x01,0x02,0x04,0x08,0x10,0x20};
		    	for(j=0;j<6;j++)
		    	{
		    		Bits1_PutVal(i[j]);
		    		Bits1_PutVal(0);
		    		//for(l=0;l<0x7ffff;l++);
		    		xTaskCreate(task_2, "task_2", 100, NULL, 11, NULL);
		    		xTaskCreate(task_3, "task_3", 100, NULL, 12, NULL);
		    		vTaskDelay(1000/portTICK_PERIOD_MS);		
		    	}*/
           cathode_PutVal(0x8);
           printf("enter task1\n");
           for(l=0;l<0x7ffff;l++);
           cathode_PutVal(0x4);
           printf("enter task1\n");
           for(l=0;l<0x7ffff;l++);
           xTaskCreate(task_2, "task_2", 100, NULL, 11, NULL);
           cathode_PutVal(0x2);
           printf("enter task1\n");
           for(l=0;l<0x7ffff;l++);
           cathode_PutVal(0x1);
           printf("enter task1\n");
           for(l=0;l<0x7ffff;l++);
           xTaskCreate(task_3, "task_3", 100, NULL, 12, NULL);
           cathode_PutVal(0);
           printf("enter task1\n");
           anode_PutVal(0x7);
           //for(l=0;l<0x7ffff;l++);
           anode_PutVal(0xB);
           printf("enter task1\n");
           //for(l=0;l<0x7ffff;l++);
           vTaskDelay(100);      
}
void task_2()
{
	                /*int j,l;
	                char i[]={0x01,0x02,0x04,0x08,0x10,0x20};
			    	for(j=0;j<6;j++)
			    	{
			    		Bits2_PutVal(~i[j]);
			    		Bits2_PutVal(0);
			    		//for(l=0;l<0x7ffff;l++);	
			    		 xTaskCreate(task_1, "task_1", 100, NULL, 10, NULL);
			    		 xTaskCreate(task_3, "task_3", 100, NULL, 12, NULL);
			    		 vTaskDelay(1000/portTICK_PERIOD_MS);		
			    	}*/
	              Bits1_PutVal(a[1]);
	              printf("enter task2\n");
	              fflush(stdout);
	              //for(l=0;l<0x7ffff;l++);
	              Bits1_PutVal(a[2]);
	              printf("enter task2\n");
	              fflush(stdout);
	             
	              vTaskDelay(100);  
	              Bits1_PutVal(a[3]);
	              printf("enter task2\n");
	              fflush(stdout);
				  //for(l=0;l<0x7ffff;l++);
				  Bits1_PutVal(a[4]);
	              printf("enter task2\n");
	              fflush(stdout);
	              //for(l=0;l<0x7ffff;l++);   	            	          
	              vTaskDelay(100);  
}
void task_3()
{
	
	/*	int p,j,k;
		unsigned char n,m;
		n=0xf0;
		for(p=0;p<4;p++)
		{
			m=n^0xf;
			anode_PutVal(m);
			n=n>>1;
			//for(k=0;k<0xffff;k++);
			anode_PutVal(1);
			xTaskCreate(task_1, "task_1", 100, NULL, 10, NULL);
		    xTaskCreate(task_2, "task_2", 100, NULL, 11, NULL);
			vTaskDelay(1000/portTICK_PERIOD_MS);		
			if(p==3)
			{
				anode_PutVal(0x0);	
			}		
		}
		n=0x8;
		for(j=0;j<4;j++)
		{
			m=n^0xf;
			cathode_PutVal(m);
			n=n>>1;
			xTaskCreate(task_1, "task_1", 100, NULL, 10, NULL);
			xTaskCreate(task_2, "task_2", 100, NULL, 11, NULL);
			//for(k=0;k<0xffff;k++);
			cathode_PutVal(0);
			vTaskDelay(1000/portTICK_PERIOD_MS);		
			if(j==3)
			{
				cathode_PutVal(0xf);	
			}		
		}*/
	  Bits2_PutVal(~(a[1]));
      printf("enter task3\n");
	  for(l=0;l<0x7ffff;l++);
	  Bits2_PutVal(~(a[2]));
	  printf("enter task3\n");
	  for(l=0;l<0x7ffff;l++);
	  Bits2_PutVal(~(a[3]));
	  printf("enter task3\n");
	  //for(l=0;l<0x7ffff;l++);
	  vTaskDelay(1000);  
}
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
  
       //task_1();
       //task_2();
       //task_3();
       xTaskCreate(task_1, "task_1", 100, NULL, 10, NULL);
      //xTaskCreate(task_2, "task_2", 100, NULL, 11, NULL);
      //xTaskCreate(task_3, "task_3", 100, NULL, 12, NULL);
       
       
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
