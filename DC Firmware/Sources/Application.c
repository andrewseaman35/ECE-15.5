/*
 * Application.c
 *
 *  Created on: 22.05.2014
 *      Author: tastyger
 */

#include "Application.h"
#include "WAIT1.h"
#include "FX1.h"
#include "FAT1.h"
#include "UTIL1.h"
#include "PORT_PDD.h"
#include "LEDController.h"
#include "SDBuffer.h"
#include "Events.h"
#include <stdlib.h>
#include <stdio.h>

//static FAT1_FATFS fileSystemObject;
static FIL fp;
static uint8_t write_buf[48];
static const int OPEN_FILE_ERROR = 0; // Red and Blue Flashing (2 Hz)
static const int END_OF_FILE_ERROR = 1; // Red and Green Flashing (2 Hz);
static const int WRITE_ERROR = 2; // Yellow and Cyan Flashing (2 Hz);
static const int ACCEL_ENABLE_ERROR = 3; // Yellow and Magenta Flashing (2 Hz);
static const int FAT_DRIVER_ERROR = 4; // Yellow and Green Flashing (2 Hz);
static const int MOUNT_FILE_SYS_ERROR = 5; // Blue and Magenta Flashing (2 Hz);
static const int GET_TIME_ERROR = 6; // Magenta and Cyan Flashing (2 Hz);
static const int CREATE_FILE_ERROR = 7; // Green and Magenta Flashing (2 Hz);

static void Err(void/*int errorCode*/) {
	for(;;){}
}

void LogToFile(DataBuffer* myBuf,char annotation, char* fileName) {
	int16_t currentBuf = myBuf->currentReadBuffer;
	//uint8_t write_buf[48];
	UINT bw;

	/* open file */
	if (FAT1_open(&fp, fileName, FA_OPEN_ALWAYS|FA_WRITE)!=FR_OK) {
	Err(/*OPEN_FILE_ERROR*/);
	}
	/* move to the end of the file */
	if (FAT1_lseek(&fp, fp.fsize) != FR_OK || fp.fptr != fp.fsize) {
	Err(/*END_OF_FILE_ERROR*/);
	}

	/* write data */
	write_buf[0] = '\0';
	//time_t run_time;
	for(int cur_buf_index=0;cur_buf_index<BUFFER_SIZE;++cur_buf_index)
	{
		/** Time Components */
		UTIL1_strcatNum8u(write_buf, sizeof(write_buf), myBuf->dataBuffer[currentBuf][cur_buf_index].time.hour);
		UTIL1_chcat(write_buf, sizeof(write_buf), ':');
		UTIL1_strcatNum8u(write_buf, sizeof(write_buf), myBuf->dataBuffer[currentBuf][cur_buf_index].time.minute);
		UTIL1_chcat(write_buf, sizeof(write_buf), ':');
		UTIL1_strcatNum8u(write_buf, sizeof(write_buf), myBuf->dataBuffer[currentBuf][cur_buf_index].time.second);
		UTIL1_chcat(write_buf, sizeof(write_buf), ':');
		UTIL1_strcatNum8u(write_buf, sizeof(write_buf), myBuf->dataBuffer[currentBuf][cur_buf_index].time.milliBig);
		UTIL1_strcatNum8u(write_buf, sizeof(write_buf), myBuf->dataBuffer[currentBuf][cur_buf_index].time.milliSmall);
		UTIL1_chcat(write_buf, sizeof(write_buf), ',');
;
		/** Accelerometer Components */
		UTIL1_strcatNum16s(write_buf, sizeof(write_buf), myBuf->dataBuffer[currentBuf][cur_buf_index].x);
		UTIL1_chcat(write_buf, sizeof(write_buf), ',');
		UTIL1_strcatNum16s(write_buf, sizeof(write_buf), myBuf->dataBuffer[currentBuf][cur_buf_index].y);
		UTIL1_chcat(write_buf, sizeof(write_buf), ',');
		UTIL1_strcatNum16s(write_buf, sizeof(write_buf), myBuf->dataBuffer[currentBuf][cur_buf_index].z);
		UTIL1_chcat(write_buf, sizeof(write_buf), ',');

		/** Annotation mode **/
		UTIL1_chcat(write_buf, sizeof(write_buf), annotation);
		UTIL1_strcat(write_buf, sizeof(write_buf), (unsigned char*)"\n");

		/** Write to file **/
		if (FAT1_write(&fp, write_buf, UTIL1_strlen((char*)write_buf), &bw)!=FR_OK) {
		  (void)FAT1_close(&fp);
		  Err(/*WRITE_ERROR*/);
		  }
		memset(write_buf,'\0',48);
	}
	if(myBuf->currentReadBuffer == currentBuf)
		myBuf->currentReadBuffer=-1;
	/* closing file */
	(void)FAT1_close(&fp);
}

/** Data Collection Session**/
void APP_Run(int sel, int collectCount)
{
	//Local variables.
	int16_t x,y,z;
	uint8_t res;
	char* fileName = malloc(sizeof(char)*256);
	extern int collecting;

	/* SD card detection: PTE6 with pull-down! */
	PORT_PDD_SetPinPullSelect(PORTE_BASE_PTR, 6, PORT_PDD_PULL_DOWN);
	PORT_PDD_SetPinPullEnable(PORTE_BASE_PTR, 6, PORT_PDD_PULL_ENABLE);

	int color;
	char annotation;
	if(sel == 0)
	{
		color = LED_RED;
		annotation = 'w';
	}
	else if(sel == 1)
	{
		color = LED_YELLOW;
		annotation = 'r';
	}
	else if(sel == 2)
	{
		color = LED_GREEN;
		annotation = 'b';
	}
	else if(sel == 3)
	{
		color = LED_CYAN;
		annotation = 'c';
	}
	else if(sel == 4)
	{
		color = LED_BLUE;
		annotation = 'B';
	}
	else if(sel == 5)
	{
		color = LED_MAGENTA;
		annotation = 't';
	}

	sprintf(fileName, "%d-%c.CSV", collectCount, annotation);

	/* create and open file */
	if (FAT1_open(&fp, fileName, FA_OPEN_ALWAYS|FA_WRITE)!=FR_OK) {
	Err(/*CREATE_FILE_ERROR*/);
	}

	/* closing file */
	(void)FAT1_close(&fp);

	int count = 1;
	DataBuffer* myBuffer = getDataBuffer();
	while(isCollectingData()==1)
	{
		if(myBuffer->currentReadBuffer!=-1)
		{
			LogToFile(myBuffer,annotation,fileName);
		}
		WAIT1_Waitms(2);
	}

	me.currentWriteIndex = 0;
}

