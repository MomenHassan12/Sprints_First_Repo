/*
 * Button.c
 *
 * Created: 4/5/2023 8:38:21 AM
 *  Author: Speed
 */ 
#include "button.h"
EN_buttonError_t BUTTON_init(u8 u8_a_buttonPort, u8 u8_a_buttonPin)
{
	EN_buttonError_t en_a_error = BUTTON_OK;
	if (u8_a_buttonPort > PORT_D)
	{
		en_a_error = WRONG_PORT_BUTTON;
	}
	else if (u8_a_buttonPin > 7)
	{
		en_a_error = WRONG_PIN_BUTTON;
	}
	else
	{
		DIO_init(u8_a_buttonPort, u8_a_buttonPin, INPUT);
		en_a_error = BUTTON_OK;
	}
	
	return en_a_error;
}

EN_buttonError_t BUTTON_read(u8 buttonPort, u8 buttonPin, u8 *buttonState)
{
	EN_buttonError_t en_a_error = BUTTON_OK;
	if (buttonPort > PORT_D)
	{
		en_a_error = WRONG_PORT_BUTTON;
	}
	else if (buttonPin > 7)
	{
		en_a_error = WRONG_PIN_BUTTON;
	}
	else
	{
		DIO_read(buttonPort, buttonPin, buttonState);
		en_a_error = BUTTON_OK;
	}
	
	return en_a_error;
}