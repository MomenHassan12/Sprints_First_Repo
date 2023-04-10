/*
 * APP.c
 *
 * Created: 4/5/2023 9:26:30 AM
 *  Author: Speed
*/

#include "APP.h"

#define	BLINK_1			0
#define	BLINK_2			1
#define	BLINK_3			2
#define	BLINK_4			3
#define BLINK_5			4
#define TURN_ON			0
#define TURN_OFF		1

uint8_t blinkMode = BLINK_1;
uint8_t timeOn = 1, timeOff = 9;
uint8_t counter = 0, tickNumber = 0 ;
volatile uint8_t state = TURN_ON;


void APP_initModules(void)
{
	
	BUTTON_init(BUTTON_0_PORT, BUTTON_0_Pin);
	BUTTON_init(BUTTON_1_PORT, BUTTON_1_Pin);
	LED_init(LED_0_PORT, LED_0_PIN);
	LED_init(LED_1_PORT, LED_1_PIN);
	LED_init(LED_2_PORT, LED_2_PIN);
	LED_init(LED_3_PORT, LED_3_PIN);
	LED_off(LED_0_PORT, LED_0_PIN);
	LED_off(LED_1_PORT, LED_1_PIN);
	LED_off(LED_2_PORT, LED_2_PIN);
	LED_off(LED_3_PORT, LED_3_PIN);
	
	EXTINT_Init(INT0);
	EXTINT_setCallBackInt(INT0, button_1_Task);
	
	TIMER_init(TIMER_0);
	TIMER_setTime(TIMER_0, 100);
	TIMER_setCallBack(TIMER_0, sysTickTask);
	TIMER_start(TIMER_0);
	
}
void APP_ledSequenceV_3 (void)
{
	while (1)
	{
		
		uint8_t button0State = 0;
		BUTTON_read(BUTTON_0_PORT, BUTTON_0_Pin, &button0State);
		if (button0State)
		{
			//_delay_ms(60);
			BUTTON_read(BUTTON_0_PORT, BUTTON_0_Pin, &button0State);
			if(button0State)
			{
				BUTTON_read(BUTTON_0_PORT, BUTTON_0_Pin, &button0State);
				counter++;
				button_0_Task(&counter, state);
				while(button0State)
				{
					BUTTON_read(BUTTON_0_PORT, BUTTON_0_Pin, &button0State);
				}
				
			}
		}
	}
}

void button_0_Task (uint8_t* counter, uint8_t state)
{
	switch (state)
	{
		case TURN_ON:
		switch(*counter)
		{
			case 1:
			LED_on(LED_0_PORT, LED_0_PIN);
			LED_off(LED_1_PORT, LED_1_PIN);
			LED_off(LED_2_PORT, LED_2_PIN);
			LED_off(LED_3_PORT, LED_3_PIN);
			break;
			
			case 2:
			LED_on(LED_0_PORT, LED_0_PIN);
			LED_on(LED_1_PORT, LED_1_PIN);
			LED_off(LED_2_PORT, LED_2_PIN);
			LED_off(LED_3_PORT, LED_3_PIN);
			break;
			
			case 3:
			LED_on(LED_0_PORT, LED_0_PIN);
			LED_on(LED_1_PORT, LED_1_PIN);
			LED_on(LED_2_PORT, LED_2_PIN);
			LED_off(LED_3_PORT, LED_3_PIN);
			break;
			
			case 4:
			LED_on(LED_0_PORT, LED_0_PIN);
			LED_on(LED_1_PORT, LED_1_PIN);
			LED_on(LED_2_PORT, LED_2_PIN);
			LED_on(LED_3_PORT, LED_3_PIN);
			break;
			
			case 5:
			LED_off(LED_0_PORT, LED_0_PIN);
			LED_on(LED_1_PORT, LED_1_PIN);
			LED_on(LED_2_PORT, LED_2_PIN);
			LED_on(LED_3_PORT, LED_3_PIN);
			break;
			
			case 6:
			LED_off(LED_0_PORT, LED_0_PIN);
			LED_off(LED_1_PORT, LED_1_PIN);
			LED_on(LED_2_PORT, LED_2_PIN);
			LED_on(LED_3_PORT, LED_3_PIN);
			break;
			
			case 7:
			LED_off(LED_0_PORT, LED_0_PIN);
			LED_off(LED_1_PORT, LED_1_PIN);
			LED_off(LED_2_PORT, LED_2_PIN);
			LED_on(LED_3_PORT, LED_3_PIN);
			break;
			
			case 8:
			LED_off(LED_0_PORT, LED_0_PIN);
			LED_off(LED_1_PORT, LED_1_PIN);
			LED_off(LED_2_PORT, LED_2_PIN);
			LED_off(LED_3_PORT, LED_3_PIN);
			*counter = 0;	break;
			
			default:
			break;
			
		}
		break;
		
		case TURN_OFF:
		LED_off(LED_0_PORT, LED_0_PIN);
		LED_off(LED_1_PORT, LED_1_PIN);
		LED_off(LED_2_PORT, LED_2_PIN);
		LED_off(LED_3_PORT, LED_3_PIN);
		break;
		
		default:
		break;
	}

}

void button_1_Task(void)
{
	switch (blinkMode)
	{
		case BLINK_1:	timeOn = 1;
		 timeOff = 9;
		 	blinkMode = BLINK_2;
			 	break;
		case BLINK_2:	timeOn = 2;
			timeOff = 8;
				blinkMode = BLINK_3;
					break;
		case BLINK_3:	
		timeOn = 3;
			timeOff = 7;	
			blinkMode = BLINK_4;	
			break;
		case BLINK_4:	timeOn = 5;
			timeOff = 5;	
			blinkMode = BLINK_5;	
			break;
		case BLINK_5:	timeOn = 8;	
		timeOff = 2;	
		blinkMode = BLINK_1;	
		break;
		default:															
		break;
	}
}


void sysTickTask (void)
{
	if (tickNumber < timeOn)
	{
		button_0_Task(&counter, TURN_ON);
		state = TURN_ON;
		tickNumber++;
	}
	else if (tickNumber >= timeOn && tickNumber < (timeOn+timeOff))
	{
		button_0_Task(&counter, TURN_OFF);
		state = TURN_OFF;
		tickNumber++;
		if (tickNumber >= (timeOn + timeOff))
		{
			tickNumber = 0;
		}
	}

}