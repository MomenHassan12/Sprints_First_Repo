#include "DIO_int.h"

EN_dioError_t DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction)
{
	EN_dioError_t error = DIO_OK;
	if (pinNumber < 8)
	{
		
		switch(direction)
		{
			case INPUT:
			switch(portNumber)
			{  
				
				case PORT_A:	CLEAR_BIT(DDRA,pinNumber);	break;
				case PORT_B:	CLEAR_BIT(DDRB,pinNumber);	break;
				case PORT_C:	CLEAR_BIT(DDRC,pinNumber);	break;
				case PORT_D:	CLEAR_BIT(DDRD,pinNumber);	break;
				default:		error = WRONG_PORT_NUMBER;	break;
			}
			break;
			
			case OUTPUT:
			switch(portNumber)
			{     SET_BIT(DDRA,pinNumber);
				case PORT_A:	SET_BIT(DDRA,pinNumber);		break;
				case PORT_B:	SET_BIT(DDRB,pinNumber);	break;
				case PORT_C:	SET_BIT(DDRC,pinNumber);		break;
				case PORT_D:	SET_BIT(DDRD,pinNumber);		break;
				default:		error = WRONG_PORT_NUMBER;	break;
			}
			break;
			
			default:
			error = WRONG_DIRECTION;
			break;
		}
		
	}
	else
	{
		error = WRONG_PIN_NUMBER;
	}
	return error;
}
EN_dioError_t DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value)
{
	
	EN_dioError_t error = DIO_OK;
	if (pinNumber < 8)
	{
		switch(value)
		{
			case LOW:
			switch(portNumber)
			{
				case PORT_A:	CLEAR_BIT(PORTA,pinNumber);	break;
				case PORT_B:	CLEAR_BIT(PORTB,pinNumber);	break;
				case PORT_C:	CLEAR_BIT(PORTC,pinNumber);	break;
				case PORT_D:	CLEAR_BIT(PORTD,pinNumber);	break;
				default:		error = WRONG_PORT_NUMBER;	break;
			}
			break;
			
			case HIGH:
			switch(portNumber)
			{
				case PORT_A:	SET_BIT(PORTA,pinNumber);		break;
				case PORT_B:	SET_BIT(PORTA,pinNumber);	    break;
				case PORT_C:	SET_BIT(PORTA,pinNumber);		break;
				case PORT_D:	SET_BIT(PORTA,pinNumber);		break;
				default:		error = WRONG_PORT_NUMBER;		break;
			}
			break;
			
			default:
			error = WRONG_VALUE;
			break;
		}
	}
	else
	{
		error = WRONG_PIN_NUMBER;
	}
	return error;
}

EN_dioError_t DIO_toggle(uint8_t portNumber, uint8_t pinNumber)
{
	EN_dioError_t DIO_toggle(uint8_t portNumber, uint8_t pinNumber)						// Toggle dio
	{
		EN_dioError_t error = DIO_OK;
		if (pinNumber < 8)
		{
			switch(portNumber)
			{
				case PORT_A:	TOGGLE_BIT(PORTA,pinNumber);		break;
				case PORT_B:	TOGGLE_BIT(PORTB,pinNumber);		break;
				case PORT_C:	TOGGLE_BIT(PORTC,pinNumber);		break;
				case PORT_D:	TOGGLE_BIT(PORTD,pinNumber);		break;
				default:		error = WRONG_PORT_NUMBER;		    break;
			}
		}
		else
		{
			error = WRONG_PIN_NUMBER;
		}
		return error;
	}
}
						
EN_dioError_t DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t *value)
{
	
	EN_dioError_t error = DIO_OK;
	if (pinNumber < 8)
	{

		switch(portNumber)
		{
			case PORT_A:	*value = GET_BIT(PINA,pinNumber);		break;
			case PORT_B:	*value = GET_BIT(PINB,pinNumber);		break;
			case PORT_C:	*value = GET_BIT(PINC,pinNumber);		break;
			case PORT_D:	*value = GET_BIT(PIND,pinNumber);		break;
			default:		error = WRONG_PORT_NUMBER;				break;
		}
	}
	else
	{
		error = WRONG_PIN_NUMBER;
	}
	return error;
}		