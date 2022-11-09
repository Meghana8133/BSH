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
//#include "Bits3.h"
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
SemaphoreHandle_t xSemaphore;
SemaphoreHandle_t xSemaphore2;
void Task3();
void Task2();

void Task1()
{
		 printf("entered 1\n");
		 printf("Took semaphore for 1\n");
		 xSemaphoreTake( xSemaphore,  portMAX_DELAY ) ;
		 printf("starting med priority task\n");
		 xTaskCreate(Task2,"Task2",100,NULL,11,NULL);
		 printf("starting high priority task\n");
		 xTaskCreate(Task3,"Task3",100,NULL,12,NULL);
		 xSemaphoreTake( xSemaphore2,portMAX_DELAY  ); 
		 printf("Returning semaphore from 1\n");
		 xSemaphoreGive( xSemaphore );   
		 printf("exiting 1\n");	
		 fflush(stdout);
		 vTaskDelay(1000/portTICK_PERIOD_MS);
}
void Task2()
{
		printf("entered med priority task\n");
	    vTaskDelay(20/portTICK_PERIOD_MS);
        printf("exiting 2\n");
	  	fflush(stdout);
	  	vTaskDelay(1000/portTICK_PERIOD_MS);
}
void Task3()
{
		printf("entered high priority task\n");
		xSemaphoreTake( xSemaphore2,  portMAX_DELAY ) ;
		printf("Took semaphore for 3\n");
		printf("Took semaphore for 3\n");			      
        xSemaphoreTake( xSemaphore,  portMAX_DELAY ) ;
        printf("Returning semaphore from 3\n");
		xSemaphoreGive( xSemaphore );
		printf("exiting 3\n");	
	    fflush(stdout);
	    vTaskDelay(1000/portTICK_PERIOD_MS);
}
/* User includes (#include below this line is not maintained by Processor Expert) */

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
 
  xSemaphore=xSemaphoreCreateMutex( );
  xSemaphore2=xSemaphoreCreateMutex( );
  printf("starting low priority task\n");
  fflush(stdout);
  xTaskCreate(Task1,"Task1",100,NULL,10,NULL);
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
