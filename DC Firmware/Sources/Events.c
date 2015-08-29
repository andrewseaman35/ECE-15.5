/* ###################################################################
**     Filename    : Events.c
**     Project     : LEDData
**     Processor   : MK64FN1M0VLL12
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-01-14, 22:10, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMI - void Cpu_OnNMI(void);
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
#include "Init_Config.h"
#include "PDD_Includes.h"
#include "TimeKeep.h"


#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

#include "LEDController.h"
#include "SDBuffer.h"

/*
** ===================================================================
**     Event       :  Cpu_OnNMI (module Events)
**
**     Component   :  Cpu [MK64FN1M0LL12]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMI(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  EInt1_OnInterrupt (module Events)
**
**     Component   :  EInt1 [ExtInt_LDD]
*/
/*!
**     @brief
**         This event is called when an active signal edge/level has
**         occurred.
**     @param
**         UserDataPtr     - Pointer to RTOS device
**                           data structure pointer.
*/
/* ===================================================================*/

int swPressCount = 0; // global variable assigned for interrupt

void EInt1_OnInterrupt(LDD_TUserData *UserDataPtr)
{
	//To prevent from int getting too large.
	swPressCount= swPressCount==7?0:++swPressCount; // Increments counter that changes mode of transportation and LED
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
  /**Just used for time-stamping*/
	addTick();
}

/*
** ===================================================================
**     Event       :  SM1_OnBlockSent (module Events)
**
**     Component   :  SM1 [SPIMaster_LDD]
*/
/*!
**     @brief
**         This event is called after the last character from the
**         output buffer is moved to the transmitter. This event is
**         available only if the SendBlock method is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer is passed
**                           as the parameter of Init method. 
*/
/* ===================================================================*/
void SM1_OnBlockSent(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  EInt2_OnInterrupt (module Events)
**
**     Component   :  EInt2 [ExtInt_LDD]
*/
/*!
**     @brief
**         This event is called when an active signal edge/level has
**         occurred.
**     @param
**         UserDataPtr     - Pointer to RTOS device
**                           data structure pointer.
*/
/* ===================================================================*/

int isCollecting = 0;
void EInt2_OnInterrupt(LDD_TUserData *UserDataPtr)
{
	if(isCollecting == 0)
		isCollecting = 1;
	else if(isCollecting == 1)
		isCollecting = 0;
  /* Write your code here ... */
}
/** Modify if the state if data is being collected**/
int isCollectingData()
{
	return isCollecting;
}

/*
** ===================================================================
**     Event       :  TI2_OnInterrupt (module Events)
**
**     Component   :  TI2 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

int itrCount = 0; int current_mode =0;
void TI2_OnInterrupt(void)
{
	itrCount= itrCount==501?0:++itrCount;
	int transMode = swPressCount%6;
	if(itrCount%250 == 0)
	{
		if(transMode == 0)
			TurnOnLEDs(LED_RED);
		else if(transMode == 1)
			TurnOnLEDs(LED_YELLOW);
		else if(transMode == 2)
			TurnOnLEDs(LED_GREEN);
		else if(transMode == 3)
			TurnOnLEDs(LED_CYAN);
		else if(transMode == 4)
			TurnOnLEDs(LED_BLUE);
		else if(transMode == 5)
			TurnOnLEDs(LED_MAGENTA);
	}
	if(isCollectingData())
	{
		writeToBuffer(current_mode);
		if(itrCount%500 == 0)
			TurnOnLEDs('x');
	}

}

/** Change the current mode the data is being collected for **/
void ChangeMode(int m_val)
{
	current_mode = m_val;
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
**     This file was created by Processor Expert 10.4 [05.11]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
