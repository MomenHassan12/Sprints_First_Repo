/*
 * LED.c
 *
 * Created: 4/5/2023 9:09:59 AM
 *  Author: Speed
 */ 

#include "LED.h"
EN_ledError_t LED_init(uint8_t ledPort,uint8_t ledPin)
{
	EN_ledError_t error = LED_OK;
	if (ledPort > PORT_D)
	{
		error = WRONG_PORT_LED;
	}
	else if (ledPin > 7)
	{
		error = WRONG_PIN_LED;
	}
	else
	{
		DIO_init(ledPort, ledPin, OUTPUT);
		error = LED_OK;
	}
	
	return error;
}

EN_ledError_t LED_on(uint8_t ledPort,uint8_t ledPin)
{
EN_ledError_t error = LED_OK;
if (ledPort > PORT_D)
{
	error = WRONG_PORT_LED;
}
else if (ledPin > 7)
{
	error = WRONG_PIN_LED;
}
else
{
	DIO_write(ledPort,ledPin,HIGH);
	error = LED_OK;
}

return error;
}

EN_ledError_t LED_off(uint8_t ledPort,uint8_t ledPin)
{
EN_ledError_t error = LED_OK;
if (ledPort > PORT_D)
{
	error = WRONG_PORT_LED;
}
else if (ledPin > 7)
{
	error = WRONG_PIN_LED;
}
else
{
	DIO_write(ledPort,ledPin,LOW);
	error = LED_OK;
}

return error;
}
EN_ledError_t LED_toggle(uint8_t ledPort,uint8_t ledPin)
{
	EN_ledError_t error = LED_OK;
	if (ledPort > PORT_D)
	{
		error = WRONG_PORT_LED;
	}
	else if (ledPin > 7)
	{
		error = WRONG_PIN_LED;
	}
	else
	{
		DIO_toggle(ledPort,ledPin);
		error = LED_OK;
	}

	return error;
}


