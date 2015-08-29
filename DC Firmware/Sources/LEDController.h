/*
 * LEDController.h
 *
 *  Created on: Jan 15, 2015
 *      Author: Andrew
 */

#ifndef LEDCONTROLLER_H_
#define LEDCONTROLLER_H_

void TurnOnLEDs(int);

typedef enum {LED_RED = 0, LED_YELLOW=1, LED_GREEN=2, LED_CYAN=3, LED_BLUE=4,
	LED_MAGENTA=5, LED_WHITE=6, LED_OFF=7} LEDColor;

#endif /* LEDCONTROLLER_H_ */
