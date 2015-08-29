/**
 * SDBuffer.c
 *
 *  Created on: Feb 2, 2015
 *      Author: Andrew S.
 *  Edited on: Feb 9, 2015
 *   	Editor: Kyle C.
 **/


#include "SDBuffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "FX1.h"
#include "TmDt1.h"
#include "LEDController.h"

/*Define of global DataBuffer */
DataBuffer me;
extern TimeKeep currentTime;

/**
 * Description: Called to construct a new DataLine object.
 * Pre-Condition: InMode is one of the valid modes associated with data collection.
 * Post-Condition: Returns a newly created DataLine.
 **/
DataLine* DataLine_new(int16_t inX, int16_t inY, int16_t inZ, int16_t inMode)
{
	DataLine* dl = malloc(sizeof(DataLine));
	dl->time = currentTime;
	dl->x = inX;
	dl->y = inY;
	dl->z = inZ;
	dl->mode = inMode;
	return dl;
}

/**
 * Description: Initializes the DataBuffer element to implement the "ping pong" buffer scheme
 * Pre-Condition: Passes the object to be initialized
 * Post-Condition: Sets up the elements to the default values of the buffer.
 **/
void init_Buffer()
{
	/** Null Initialize elements **/
	for(int current_buffer = 0;current_buffer<NUMBER_OF_BUFFERS;++current_buffer)
	{
		for(int current_data_line = 0;current_data_line<BUFFER_SIZE;++current_data_line)
		{
			me.dataBuffer[current_buffer][current_data_line].mode = -1;
			me.dataBuffer[current_buffer][current_data_line].x = 0;
			me.dataBuffer[current_buffer][current_data_line].y = 0;
			me.dataBuffer[current_buffer][current_data_line].z = 0;
			me.dataBuffer[current_buffer][current_data_line].time = currentTime;
		}
	}
	me.currentReadBuffer = -1; //Nothing to read
	me.currentWriteBuffer = 0;
	me.currentWriteIndex = 0;
}

/**
 * Description: Swap the current writing buffer to the next one.
 * Pre-Condition: DataBuffer has been initialized.
 * Post-Condition: Swaps currentWriteBuffer to the next bufferIndex. Changes the value of readBuffer to old index.
 **/
void swap_Buffer()
{
	me.currentReadBuffer= me.currentWriteBuffer;
	me.currentWriteBuffer= (me.currentWriteBuffer==NUMBER_OF_BUFFERS-1)?0:++me.currentWriteBuffer;
	me.currentWriteIndex = 0;
}

/**
 * Description: Writes dataLine to the buffer that is currently active.
 * Pre-Condition: DataBuffer's init() has been called, dataLine has been instantiated
 * Post-Condition: Adds the dataLine to the currentActive DataBuffer
 **/
void writeToBuffer(int cur_mode)
{
	if(me.currentWriteIndex == BUFFER_SIZE)
	{
		swap_Buffer();
	}
	me.dataBuffer[me.currentWriteBuffer][me.currentWriteIndex].x = (FX1_GetX() + X_OFFSET);
	me.dataBuffer[me.currentWriteBuffer][me.currentWriteIndex].y = (FX1_GetY() + Y_OFFSET);
	me.dataBuffer[me.currentWriteBuffer][me.currentWriteIndex].z = (FX1_GetZ() + Z_OFFSET);
	me.dataBuffer[me.currentWriteBuffer][me.currentWriteIndex].mode = cur_mode;
	me.dataBuffer[me.currentWriteBuffer][me.currentWriteIndex].time = currentTime;
	me.currentWriteIndex++;
}

DataBuffer* getDataBuffer()
{
	return &me;
}


