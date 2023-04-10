/*
 * Button.h
 *
 * Created: 4/5/2023 8:36:39 AM
 *  Author: Speed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO_DRIVER/DIO_int.h"

#define BUTTON_0_PORT	PORT_D
#define BUTTON_0_Pin	0
#define BUTTON_1_PORT	PORT_D
#define BUTTON_1_Pin	2


typedef enum buttonErrors{
	BUTTON_OK,
	WRONG_PORT_BUTTON,
	WRONG_PIN_BUTTON
}EN_buttonError_t;

EN_buttonError_t BUTTON_init(uint8_t buttonPort, uint8_t buttonPin);

EN_buttonError_t BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *buttonState);






#endif /* BUTTON_H_ */