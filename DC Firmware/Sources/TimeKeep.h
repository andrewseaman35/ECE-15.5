#ifndef TIMEKEEP_H_
#define TIMEKEEP_H_

#include <stdint.h>
#include "UTIL1.h"

#define MILLIS_PER_BIG_PART 100
#define MILLIS_PER_SMALL_PART 10
#define SECONDS_PER_MINUTE 60
#define MINUTES_PER_HOUR 60

typedef struct TimeKeep{
	uint16_t milliSmall;
	uint16_t milliBig;
	uint16_t second;
	uint16_t minute;
	uint16_t hour;
}TimeKeep;

void clearTimeKeep();
void addTick();

#endif
