/*
 * APP.c
 *
 * Created: 4/5/2023 9:26:30 AM
 *  Author: Speed
*/

#include "APP.h"

void APP_initModules(void)
{
	DIO_init(PORT_D,2,INPUT);
	DIO_write(PORT_D,2,HIGH);
LED_init(LED_0_PORT, LED_0_PIN);
LED_init(LED_1_PORT, LED_1_PIN);
LED_init(LED_2_PORT, LED_2_PIN);
LED_init(LED_3_PORT, LED_3_PIN);
LED_off(LED_0_PORT, LED_0_PIN);
LED_off(LED_1_PORT, LED_1_PIN);
LED_off(LED_2_PORT, LED_2_PIN);
LED_off(LED_3_PORT, LED_3_PIN);
}

void APP_ledUnitTesting (void)
{
LED_on(LED_1_PORT,LED_1_PIN);
}

void APP_ledSequenceV2 (void)
  {
sei();

EXT_INT_TriggerEdge(EX_INT0,RISING_EDGE);
EXT_INT_Enable(EX_INT0);

  }
  