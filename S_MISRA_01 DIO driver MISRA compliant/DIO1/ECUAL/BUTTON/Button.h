/*
 * Button.h
 *
 * Created: 4/5/2023 8:36:39 AM
 *  Author: Speed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO/DIO.h"

#define BUTTON_0_PORT	PORT_B
#define BUTTON_0_Pin	0

typedef enum buttonErrors{
	BUTTON_OK,
	WRONG_PORT_BUTTON,
	WRONG_PIN_BUTTON
}EN_buttonError_t;

EN_buttonError_t BUTTON_init(u8 buttonPort, u8 buttonPin);

EN_buttonError_t BUTTON_read(u8 buttonPort, u8 buttonPin, u8 *buttonState);






#endif /* BUTTON_H_ */