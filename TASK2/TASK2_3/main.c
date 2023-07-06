/*
 * FreeRTOS Kernel V10.2.0
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/* 
	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used.
*/


/*
 * Creates all the demo application tasks, then starts the scheduler.  The WEB
 * documentation provides more details of the demo application tasks.
 * 
 * Main.c also creates a task called "Check".  This only executes every three 
 * seconds but has the highest priority so is guaranteed to get processor time.  
 * Its main function is to check that all the other tasks are still operational.
 * Each task (other than the "flash" tasks) maintains a unique count that is 
 * incremented each time the task successfully completes its function.  Should 
 * any error occur within such a task the count is permanently halted.  The 
 * check task inspects the count of each task to ensure it has changed since
 * the last time the check task executed.  If all the count variables have 
 * changed all the tasks are still executing error free, and the check task
 * toggles the onboard LED.  Should any task contain an error at any time 
 * the LED toggle rate will change from 3 seconds to 500ms.
 *
 */

/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "lpc21xx.h"

/* Peripheral includes. */
#include "serial.h"
#include "GPIO.h"
#include "semphr.h"
#include "event_groups.h"

/*-----------------------------------------------------------*/

#define EVENT_BUTTON_1_RISING (1 << 0)
#define EVENT_BUTTON_1_FALLING (1 << 1)
#define EVENT_BUTTON_2_RISING (1 << 2)
#define EVENT_BUTTON_2_FALLING (1 << 3)
#define EVENT_PERIODIC_STRING (1 << 4)

/* Constants to setup I/O and processor. */
#define mainBUS_CLK_FULL	( ( unsigned char ) 0x01 )

/* Constants for the ComTest demo application tasks. */
#define mainCOM_TEST_BAUD_RATE	( ( unsigned long ) 115200 )
TaskHandle_t LedTask_Handler=NULL;
EventGroupHandle_t  eventGroup;
QueueHandle_t mailbox;
/*
 * Configure the processor for use with the Keil demo board.  This is very
 * minimal as most of the setup is managed by the settings in the project
 * file.
 */
static void prvSetupHardware( void );
/*-----------------------------------------------------------*/

 
// Button task 1
void buttonTask1(void *pvParameters) {
  pinState_t lastState = 0;
  pinState_t currentState=0;
 for(;;) {


    // Read button state
   currentState = GPIO_read(PORT_0,PIN0);

    // Check for rising edge
    if (currentState == 1 && lastState == 0) {
      // Send rising edge event to consumer task
      xEventGroupSetBits(eventGroup, EVENT_BUTTON_1_RISING);
    }

    // Check for falling edge
    if (currentState == 0 && lastState == 1) {
      // Send falling edge event to consumer task
      xEventGroupSetBits(eventGroup, EVENT_BUTTON_1_FALLING);
    }

    lastState = currentState;
      vTaskDelay(50);

	}
}
	
	  // Button task 2
void buttonTask2(void *pvParameters) {

 pinState_t lastState = 0;
	pinState_t currentState=0;
  for(;;) {
    // Simulate button state change

    // Read button state
     currentState = GPIO_read(PORT_0,PIN1);

    // Check for rising edge
    if (currentState == 1 && lastState == 0) {
      // Send rising edge event to consumer task
      xEventGroupSetBits(eventGroup, EVENT_BUTTON_2_RISING);
    }

    // Check for falling edge
    if (currentState == 0 && lastState == 1) {
      // Send falling edge event to consumer task
      xEventGroupSetBits(eventGroup, EVENT_BUTTON_2_FALLING);
    }

    lastState = currentState;
    vTaskDelay(50);
 
	}
}
// Periodic string task
void periodicStringTask(void *pvParameters) {
  const char *message = "Periodic_String\n ";

 for(;;) {
    // Send periodic string to consumer task
    xQueueSend(mailbox, &message, portMAX_DELAY);
    
    // Set periodic string event
    xEventGroupSetBits(eventGroup, EVENT_PERIODIC_STRING);

    vTaskDelay(100);
  }
}
// Consumer task
void consumerTask(void *pvParameters) {
  const TickType_t xMaxBlockTime = pdMS_TO_TICKS(100);
  const char *receivedMessage;

  for(;;) {
    EventBits_t events = xEventGroupWaitBits(eventGroup, EVENT_BUTTON_1_RISING | EVENT_BUTTON_1_FALLING | EVENT_BUTTON_2_RISING | EVENT_BUTTON_2_FALLING | EVENT_PERIODIC_STRING, pdTRUE, pdFALSE, xMaxBlockTime);
			 const char *button_1_r = "\nBUTTON_1_RISING";
			 const char *button_1_f = "\nBUTTON_1_FALLING ";
			 const char *button_2_r = "\nBUTTON_2_RISING ";
			 const char *button_2_f = "\nBUTTON_2_FALLING ";
		
    // Handle events
    if (events & EVENT_BUTTON_1_RISING) {
      // Write button 1 rising edge to UART
  vSerialPutString(button_1_r,17);
}
    if (events & EVENT_BUTTON_1_FALLING) {
      // Write button 1 falling edge to UART   
			/* Write to UART */
  vSerialPutString(button_1_f,17);

    }
    if (events & EVENT_BUTTON_2_RISING) {
      // Write button 2 rising edge to UART
      /* Write to UART */
			  vSerialPutString(button_2_r,17);
    }
    if (events & EVENT_BUTTON_2_FALLING) {
      // Write button 2 falling edge to UART
      /* Write to UART */
				  vSerialPutString(button_2_f,17);
    }
    if (events & EVENT_PERIODIC_STRING) {
      // Receive periodic string from mailbox
      if (xQueueReceive(mailbox, &receivedMessage, 0) == pdTRUE) {
			  vSerialPutString(receivedMessage,15);
				// Write periodic string to UART
        /* Write to UART */
      }
    }
      vTaskDelay(50);

	}
}


/*
 * Application entry point:
 * Starts all the other tasks, then starts the scheduler. 
 */
int main( void )
{
	/* Setup the hardware for use with the Keil demo board. */
	  // Create the event group
  eventGroup = xEventGroupCreate();

  // Create the mailbox
  mailbox = xQueueCreate(1, sizeof(const char*));
	prvSetupHardware();
    /* Create Tasks here */
xTaskCreate(
	
	buttonTask1,
	"buttonTask1",
	configMINIMAL_STACK_SIZE,
	(void*) NULL,
		1,
	&LedTask_Handler);
xTaskCreate(
	
	buttonTask2,
	"buttonTask2",
	configMINIMAL_STACK_SIZE,
	(void*) NULL,
		1,
	&LedTask_Handler);
	
	xTaskCreate(
	
	periodicStringTask,
	"periodicStringTask",
	configMINIMAL_STACK_SIZE,
	(void*) NULL,
		1,
	&LedTask_Handler);
	
xTaskCreate(
	
	consumerTask,
	"consumerTask",
	configMINIMAL_STACK_SIZE,
	(void*) NULL,
		1,
	&LedTask_Handler);

	/* Now all the tasks have been started - start the scheduler.

	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used here. */
	vTaskStartScheduler();

	/* Should never reach here!  If you do then there was not enough heap
	available for the idle task to be created. */
	for( ;; );
}
/*-----------------------------------------------------------*/

/* Function to reset timer 1 */
void timer1Reset(void)
{
	T1TCR |= 0x2;
	T1TCR &= ~0x2;
}

/* Function to initialize and start timer 1 */
static void configTimer1(void)
{
	T1PR = 1000;
	T1TCR |= 0x1;
}

static void prvSetupHardware( void )
{
	/* Perform the hardware setup required.  This is minimal as most of the
	setup is managed by the settings in the project file. */

	/* Configure UART */
	xSerialPortInitMinimal(mainCOM_TEST_BAUD_RATE);

	/* Configure GPIO */
	GPIO_init();
	
	/* Config trace timer 1 and read T1TC to get current tick */
	configTimer1();

	/* Setup the peripheral bus to be the same as the PLL output. */
	VPBDIV = mainBUS_CLK_FULL;
}
/*-----------------------------------------------------------*/


