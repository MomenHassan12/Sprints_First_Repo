/*
 * dio.c
 *
 * Created: 4/3/2023 4:15:37 PM
 *  Author: Momen Hassan
 */ 

#include "dio.h"


en_dioError_t DIO_init(u8 u8_a_portNumber, u8 u8_a_pinNumber, u8 u8_a_direction)	// Initialize dio direction
{
	en_dioError_t error = DIO_OK;
	if ((u8_a_pinNumber < PinMax) == TRUE)
	{
		if (u8_a_direction == INPUT)
		{
			if (u8_a_portNumber == PORT_A)
			DDRA &= ~(1 << u8_a_pinNumber);
			else if (u8_a_portNumber == PORT_B)
			DDRB &= ~(1 << u8_a_pinNumber);
			else if (u8_a_portNumber == PORT_C)
			DDRC &= ~(1 << u8_a_pinNumber);
			else if (u8_a_portNumber == PORT_D)
			DDRD &= ~(1 << u8_a_pinNumber);
			else
			error = WRONG_PORT_NUMBER;
		}
		else if (u8_a_direction == OUTPUT)
		{
			if (u8_a_portNumber == PORT_A)
			DDRA |= (1 << u8_a_pinNumber);
			else if (u8_a_portNumber == PORT_B)
			DDRB |= (1 << u8_a_pinNumber);
			else if (u8_a_portNumber == PORT_C)
			DDRC |= (1 << u8_a_pinNumber);
			else if (u8_a_portNumber == PORT_D)
			DDRD |= (1 << u8_a_pinNumber);
			else
			error = WRONG_PORT_NUMBER;
		}
		else
		{
			error = WRONG_DIRECTION;
		}
	}
	else
	{
		error = WRONG_PIN_NUMBER;
	}
	return error;
}

en_dioError_t DIO_write(u8 u8_a_portNumber, u8 u8_a_pinNumber, u8 u8_a_value)		// Write data to dio
{
	en_dioError_t error = DIO_OK;
	if ((u8_a_pinNumber < PinMax) == TRUE)
	{
		if (u8_a_value == LOW)
		{
			if (u8_a_portNumber == PORT_A)
			PORTA &= ~(1 << u8_a_pinNumber);
			else if (u8_a_portNumber == PORT_B)
			PORTB &= ~(1 << u8_a_pinNumber);
			else if (u8_a_portNumber == PORT_C)
			PORTC &= ~(1 << u8_a_pinNumber);
			else if (u8_a_portNumber == PORT_D)
			PORTD &= ~(1 << u8_a_pinNumber);
			else
			error = WRONG_PORT_NUMBER;
		}
		else if (u8_a_value == HIGH)
		{
			if (u8_a_portNumber == PORT_A)
			PORTA |= (1 << u8_a_pinNumber);
			else if (u8_a_portNumber == PORT_B)
			PORTB |= (1 << u8_a_pinNumber);
			else if (u8_a_portNumber == PORT_C)
			PORTC |= (1 << u8_a_pinNumber);
			else if (u8_a_portNumber == PORT_D)
			PORTD |= (1 << u8_a_pinNumber);
			else
			error = WRONG_PORT_NUMBER;
		}
		else
		{
			error = WRONG_VALUE;
		}
	}
	else
	{
		error = WRONG_PIN_NUMBER;
	}
	return error;
}

en_dioError_t DIO_toggle(u8 u8_a_portNumber, u8 u8_a_pinNumber)						// Toggle dio
{
	en_dioError_t error = DIO_OK;
	if ((u8_a_pinNumber < PinMax) == TRUE)
	{
		if (u8_a_portNumber == PORT_A)
		TGL_BIT(PORTA, u8_a_pinNumber);
		else if (u8_a_portNumber == PORT_B)
		TGL_BIT(PORTB, u8_a_pinNumber);
		else if (u8_a_portNumber == PORT_C)
		TGL_BIT(PORTC, u8_a_pinNumber);
		else if (u8_a_portNumber == PORT_D)
		TGL_BIT(PORTD, u8_a_pinNumber);
		else
		error = WRONG_PORT_NUMBER;
	}
	else
	{
		error = WRONG_PIN_NUMBER;
	}
	return error;
}

en_dioError_t DIO_read(u8 u8_a_portNumber, u8 u8_a_pinNumber, u8 *u8_a_value)		// Read dio
{
	en_dioError_t error = DIO_OK;
	if ((u8_a_pinNumber < PinMax) == TRUE)
	{
		if (u8_a_portNumber == PORT_A)
		*u8_a_value = GET_BIT(PINA, u8_a_pinNumber);
		else if (u8_a_portNumber == PORT_B)
		*u8_a_value = GET_BIT(PINB, u8_a_pinNumber);
		else if (u8_a_portNumber == PORT_C)
		*u8_a_value = GET_BIT(PINC, u8_a_pinNumber);
		else if (u8_a_portNumber == PORT_D)
		*u8_a_value = GET_BIT(PIND, u8_a_pinNumber);
		else
		error = WRONG_PORT_NUMBER;
	}
	else
	{
		error = WRONG_PIN_NUMBER;
	}
	return error;
}

en_dioError_t DIO_pinPullUp(u8 u8_a_portNumber, u8 u8_a_pinNumber, u8 pullUpState)
{
	en_dioError_t error = DIO_OK;
	if ((u8_a_pinNumber < PinMax) == TRUE)
	{
		if (pullUpState == PULLUP_DISABLE)
		{
			if (u8_a_portNumber == PORT_A)
			CLR_BIT(PORTA, u8_a_pinNumber);
			else if (u8_a_portNumber == PORT_B)
			CLR_BIT(PORTB, u8_a_pinNumber);
			else if (u8_a_portNumber == PORT_C)
			CLR_BIT(PORTC, u8_a_pinNumber);
			else if (u8_a_portNumber == PORT_D)
			CLR_BIT(PORTD, u8_a_pinNumber);
			else
			error = WRONG_PORT_NUMBER;
		}
		else if (pullUpState == PULLUP_ENABLE)
		{
			if (u8_a_portNumber == PORT_A)
			SET_BIT(PORTA, u8_a_pinNumber);
			else if (u8_a_portNumber == PORT_B)
			SET_BIT(PORTB, u8_a_pinNumber);
			else if (u8_a_portNumber == PORT_C)
			SET_BIT(PORTC, u8_a_pinNumber);
			else if (u8_a_portNumber == PORT_D)
			SET_BIT(PORTD, u8_a_pinNumber);
			else
			error = WRONG_PORT_NUMBER;
		}
		else
		{
			error = WRONG_VALUE;
		}
	}
	else
	{
		error = WRONG_PIN_NUMBER;
	}
	return error;
}