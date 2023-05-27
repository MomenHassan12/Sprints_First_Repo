/*
 * app.h
 *
 * Created: 5/25/2023 6:54:37 PM
 *  Author: Speed
 */ 


#ifndef APP_H_
#define APP_H_
#include "../MCAL/DIO/dio.h"
#include "../service/BCM/bcm.h"
#include "../HAL/LED/led.h"
#define LED0 PINA4
#define LED1 PINA5

void app_init(void);
void app_super_loop();


#endif /* APP_H_ */