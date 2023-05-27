/*
 * led.h
 *
 * Created: 5/26/2023 4:38:27 PM
 *  Author: Speed
 */ 


#ifndef LED_H_
#define LED_H_
// include .h files
#include "../../COMMON/STD_TYPES.h"
#include "../../MCAL/dio/dio.h"


/**
 * Initializes LED on given port & pin
 * @param ledPort [in] LED Port
 * @param ledPin [in] LED Pin number in ledPort
 */
void LED_init( Uchar8_t ledPin)
;   // initialize LED

/**
 * Turns on LED at given port/pin
 * @param ledPort [in] LED Port
 * @param ledPin [in] LED Pin number in ledPort
 */
void LED_on(Uchar8_t ledPin);     // turn LED on

/**
 * Turns off LED at given port/pin
 * @param ledPort [in] LED Port
 * @param ledPin [in] LED Pin number in ledPort
 */
void LED_off(Uchar8_t ledPin);    // turn LED off

/**
 * Toggles LED at given port/pin
 * @param ledPort [in] LED Port
 * @param ledPin [in] LED Pin number in ledPort
 */
void LED_toggle(Uchar8_t ledPin); // toggle LED




#endif /* LED_H_ */