/*
 * LED.h
 *
 * Created: 4/5/2023 9:09:41 AM
 *  Author: Speed
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/dio.h"

#define LED_0_PORT		PORT_A
#define LED_1_PORT		PORT_A
#define LED_2_PORT		PORT_A
#define LED_3_PORT		PORT_A
#define LED_0_PIN		0
#define LED_1_PIN		1
#define LED_2_PIN		2
#define LED_3_PIN		3

typedef enum ledErrors{
	LED_OK,
	WRONG_PORT_LED,
	WRONG_PIN_LED
}EN_ledError_t;



EN_ledError_t LED_init(u8 ledPort,u8 ledPin);

EN_ledError_t LED_on(u8 ledPort,u8 ledPin);

EN_ledError_t LED_off(u8 ledPort,u8 ledPin);

EN_ledError_t LED_toggle(u8 ledPort,u8 ledPin);



#endif /* LED_H_ */