/* ###################################################################
**     Filename    : main.c
**     Project     : LEDData
**     Processor   : MK64FN1M0VLL12
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-01-14, 22:10, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "LED_R.h"
#include "LED_G.h"
#include "LED_B.h"
#include "EInt1.h"
#include "FAT1.h"
#include "SD1.h"
#include "SS1.h"
#include "CD1.h"
#include "TmDt1.h"
#include "UTIL1.h"
#include "SM1.h"
#include "WAIT1.h"
#include "TMOUT1.h"
#include "CS1.h"
#include "TI1.h"
#include "TimerIntLdd1.h"
#include "TU1.h"
#include "FX1.h"
#include "GI2C1.h"
#include "CI2C1.h"
#include "EInt2.h"
#include "TI2.h"
#include "TimerIntLdd2.h"
#include "TU2.h"

/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PDD_Includes.h"
#include "Init_Config.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
#include "Application.h"
#include "LEDController.h"
#include "TimeKeep.h"

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{

	/* Write your local variable definition here */

	extern int swPressCount; // we are using the variable declared in ‘Events.c’
	extern int isCollecting; // using variable in 'Events.c'

	static FAT1_FATFS fileSystemObject;

	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/

	PE_low_level_init();
	/*** End of Processor Expert internal initialization.                    ***/

	init_Buffer();

	int mode = 0; // Used with swPressCount to select mode
	int collectCount = 0;

	LDD_TDeviceData *Red_Ptr, *Green_Ptr, *Blue_Ptr; // declaring pointer variable for Red, Blue, Green LED’s

	if (FAT1_Init()!=ERR_OK) { /* initialize FAT driver */
	  //Err();
	}
	if (FAT1_mount(&fileSystemObject, "0", 1) != FR_OK) { /* mount file system */
	  //Err();
	}

	uint8_t res = FX1_Enable(); /* enable accelerometer (just in case) */
	if (res!=ERR_OK) {
	//Err(/*ACCEL_ENABLE_ERROR*/);
	}
	FX1_RECONFIGURE_RANGE();
  for(;;)
  {
	  mode = swPressCount % 6; // in order to detect the key press we are using modulo operator
	  if(mode == 0 && isCollecting == 0){
		  TurnOnLEDs(LED_RED);
	  }
	  if (mode == 1 && isCollecting == 0)
	  {
		  TurnOnLEDs(LED_YELLOW);
	  }
	  if (mode == 2 && isCollecting == 0)
	  {
		  TurnOnLEDs(LED_GREEN);
	  }
	  if (mode == 3 && isCollecting == 0)
	  {
		  TurnOnLEDs(LED_CYAN);
	  }
	  if (mode == 4 && isCollecting == 0)
	  {
		  TurnOnLEDs(LED_BLUE);
	  }
	  if(mode == 5 && isCollecting == 0)
	  {
		  TurnOnLEDs(LED_MAGENTA);
	  }
	  if(isCollecting == 1) // begins collection
	  {
		  clearTimeKeep();
		  APP_Run(mode, collectCount);//Start the data collection process.
		  ++collectCount;
	  }
  }

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

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.4 [05.11]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
