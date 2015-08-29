/*
 * SDBuffer.h
 *
 *  Created on: Feb 2, 2015
 *      Author: Andrew S.
 *  Edited on: Feb 9, 2015
 *  	Editor: Kyle C.
 */

#ifndef SDBUFFER_H_
#define SDBUFFER_H_

#include <stdint.h>
#include <time.h>
#include <stdbool.h>
#include "TmDt1.h"
#include "TimeKeep.h"

/**
 * Define Buffer Size and number of buffers to have.
 */
#define BUFFER_SIZE 1024
#define NUMBER_OF_BUFFERS 3
#define STRING_SIZE 32
#define X_OFFSET 0
#define Y_OFFSET 0
#define Z_OFFSET 0

/**
 * Used to hold the individual lines of accelerometer data.
 */
typedef struct DataLine
{
	TimeKeep time;
	int16_t x;
	int16_t y;
	int16_t z;
	int16_t mode;
	char string_value[STRING_SIZE];
}DataLine;

/**
 * Used to hold the dataBuffer, current Indices for Writing & Reading and Write Index within the current buffer.
 */
typedef struct DataBuffer
{
	DataLine dataBuffer[NUMBER_OF_BUFFERS][BUFFER_SIZE];
	int16_t currentWriteIndex;
	int16_t currentReadBuffer;
	int16_t currentWriteBuffer;
}DataBuffer;

/** Defines the buffer used for implementing the Ping Pong buffer scheme*/
extern DataBuffer me;

/** Initializes the GlobalBuffer used for Storing/Writing Acc. Data. **/
void init_Buffer();

/** Writes current DataLine to the DataBuffer **/
void writeToBuffer(int cur_mode);

/**
 * Description: Used to extract the DataBuffer for reading purposes.
 * Pre-Condition: init_Buffer() has been called.
 * Post-Condition: Returns the pointer to the DataBuffer me.
 */
DataBuffer* getDataBuffer();

#endif /* SDBUFFER_H_ */

