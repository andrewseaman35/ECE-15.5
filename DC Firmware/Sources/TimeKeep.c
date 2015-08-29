
#include "TimeKeep.h"

TimeKeep currentTime;

void clearTimeKeep()
{
	currentTime.milliSmall = -1;
	currentTime.milliBig = 0;
	currentTime.second = 0;
	currentTime.minute = 0;
	currentTime.hour = 0;
}

void addTick()
{
	++currentTime.milliSmall;
	if(currentTime.milliSmall == MILLIS_PER_SMALL_PART)
	{
		currentTime.milliSmall = 0;
		++currentTime.milliBig;
		if(currentTime.milliBig == MILLIS_PER_BIG_PART)
		{
			currentTime.milliBig = 0;
			++currentTime.second;
		if(currentTime.second == SECONDS_PER_MINUTE)
		{
			currentTime.second = 0;
			++currentTime.minute;
			if(currentTime.minute == MINUTES_PER_HOUR)
			{
				currentTime.minute = 0;
				++currentTime.hour;
			}
		}
		}
	}
}
