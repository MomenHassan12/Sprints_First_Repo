/*
 * dio.h
 *
 * Created: 4/3/2023 4:15:52 PM
 *  Author: Momen Hassan
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../registers.h"
#include "../../COMMON/bit_math.h"

// all internal driver typedefs
// all driver macros
#define PORT_A			'A'
#define PORT_B			'B'
#define PORT_C			'C'
#define PORT_D			'D'

#define INPUT			0
#define OUTPUT			1

#define LOW				0
#define HIGH			1

#define PULLUP_DISABLE	0
#define PULLUP_ENABLE	1
#define PinMax          8
#define TRUE            1  
// all driver function prototypes
typedef enum dioError{
	DIO_OK,
	WRONG_PORT_NUMBER,
	WRONG_PIN_NUMBER,
	WRONG_VALUE,
	WRONG_DIRECTION
	}en_dioError_t;

/******************************************************************************
* \Syntax          : en_dioError_t DIO_init(u8 u8_a_portNumber, u8 u8_a_pinNumber, u8 u8_a_direction)
* \Description     : Initializes DIO pins’ direction, output current.
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : u8_a_portNumber	port number used
*					 u8_a_pinNumber		pin number used
*					 u8_a_direction		direction of the pin
* \Parameters (out): None
* \Return value:   : en_dioError_t		DIO_OK
*										WRONG_PIN_NUMBER
*										WRONG_PORT_NUMBER
*										WRONG_DIRECTION
*******************************************************************************/
en_dioError_t DIO_init(u8 u8_a_portNumber, u8 u8_a_pinNumber, u8 u8_a_direction);

/******************************************************************************
* \Syntax          : en_dioError_t DIO_write(u8 u8_a_portNumber, u8 u8_a_pinNumber, u8 u8_a_value)
* \Description     : Write on DIO pins’ a specific output High or Low.
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : u8_a_portNumber	port number used
*					 u8_a_pinNumber		pin number used
*					 u8_a_value			output value on the pin
* \Parameters (out): None
* \Return value:   : en_dioError_t		DIO_OK
*										WRONG_PIN_NUMBER
*										WRONG_PORT_NUMBER
*										WRONG_VALUE
*******************************************************************************/	
en_dioError_t DIO_write(u8 u8_a_portNumber, u8 u8_a_pinNumber, u8 u8_a_value);	

/******************************************************************************
* \Syntax          : en_dioError_t DIO_toggle(u8 u8_a_portNumber, u8 u8_a_pinNumber)
* \Description     : Toggle the output of a specific pin.
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : u8_a_portNumber	port number used
*					 u8_a_pinNumber		pin number used
* \Parameters (out): None
* \Return value:   : en_dioError_t		DIO_OK
*										WRONG_PIN_NUMBER
*										WRONG_PORT_NUMBER
*******************************************************************************/	
en_dioError_t DIO_toggle(u8 u8_a_portNumber, u8 u8_a_pinNumber);


/******************************************************************************
* \Syntax          : en_dioError_t DIO_read(u8 u8_a_portNumber, u8 u8_a_pinNumber, u8 *u8_a_value)
* \Description     : Read input from a pin and send it back in a pointer to u8
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : u8_a_portNumber	port number used
*					 u8_a_pinNumber		pin number used
* \Parameters (out): u8_a_value			input value will be returned in that parameter
* \Return value:   : en_dioError_t		DIO_OK
*										WRONG_PIN_NUMBER
*										WRONG_PORT_NUMBER
*******************************************************************************/						
en_dioError_t DIO_read(u8 u8_a_portNumber, u8 u8_a_pinNumber, u8 *u8_a_value);	

/******************************************************************************
* \Syntax          : en_dioError_t DIO_pinPullUp(u8 u8_a_portNumber, u8 u8_a_pinNumber, u8 pullUpState)
* \Description     : Disables/enables a pull up resistor to a specific input pin
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : u8_a_portNumber	port number used
*					 u8_a_pinNumber		pin number used
* \Parameters (out): None
* \Return value:   : en_dioError_t		DIO_OK
*										WRONG_PIN_NUMBER
*										WRONG_PORT_NUMBER
*										WRONG_VALUE
*******************************************************************************/	
en_dioError_t DIO_pinPullUp(u8 u8_a_portNumber, u8 u8_a_pinNumber, u8 pullUpState);

#endif /* DIO_H_ */