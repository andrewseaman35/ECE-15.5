/**
 * LEDController.c
 *
 *  Created on: Jan 15, 2015
 *      Author: Andrew S.
 *  Edited on: Feb 9, 2015
 *  	Editor: Kyle C.
 **/

#include "LEDController.h"
#include "PE_Types.h"

static LDD_TDeviceData *Red_Ptr, *Green_Ptr, *Blue_Ptr; // declaring pointer variable for Red, Blue, Green LED’s

/**
 * Description: Toggles the LED color based upon the input color.
 * PreCondition: inColor is one of the specified colors with a specific mode.
 * PostCondition: Adjusts RGB NegVals in order to adjust to the specified input color.
 */
void TurnOnLEDs(int inColor)
{
	// Turn all LEDs off
	LED_R_SetVal(Red_Ptr);
	LED_G_SetVal(Green_Ptr);
	LED_B_SetVal(Blue_Ptr);
	LEDColor myColor = inColor;
	switch(myColor)
	{
	case LED_RED:
		LED_R_NegVal(Red_Ptr);
		break;
	case LED_YELLOW:
		LED_G_NegVal(Green_Ptr);
		LED_R_NegVal(Red_Ptr);
		break;
	case LED_GREEN:
		LED_G_NegVal(Green_Ptr);
		break;
	case LED_CYAN:
		LED_G_NegVal(Green_Ptr);
		LED_B_NegVal(Blue_Ptr);
		break;
	case LED_BLUE:
		LED_B_NegVal(Blue_Ptr);
		break;
	case LED_MAGENTA:
		LED_B_NegVal(Blue_Ptr);
		LED_R_NegVal(Red_Ptr);
		break;
	case LED_WHITE:
		LED_R_NegVal(Red_Ptr);
		LED_G_NegVal(Green_Ptr);
		LED_B_NegVal(Blue_Ptr);
		break;
	}
}
