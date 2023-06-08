/*
 * timer.h
 *
 * Created: 4/5/2023 12:38:41 AM
 *  Author: Momen Hassan
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../registers.h"
#include "../../COMMON/bit_math.h"
#include "../interrupts.h"
#include "../dio/dio.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
// TIMER NUMBERS
#define TIMER_0									0
#define TIMER_1									1
#define TIMER_2									2



// TIMER WAVEFORM TYPES
#define OV_TIMER								0
#define CTC_TIMER								1

// PRESCALER OPTIONS
#define NO_CLK									0
#define PRESCLNG_1								1
#define PRESCLNG_8								8
#define PRESCLNG_64								64
#define PRESCLNG_256							256
#define PRESCLNG_1024							1024
#define XCK_FLNG_EDGE							10
#define XCK_RSNG_EDGE							15

/******************************************_CONFIGURATIONS_***************************************/
/*****************************************_TIMER_MODE_USED_***************************************/

#define TIMER_0_MODE							OV_TIMER
#define TIMER_1_MODE							OV_TIMER
#define TIMER_2_MODE							OV_TIMER
/*****************************************_PRESCALER_USED_***************************************/
#define TIMER_0_PRESCALER						PRESCLNG_256
#define TIMER_1_PRESCALER						PRESCLNG_256
#define TIMER_2_PRESCALER						PRESCLNG_256

/**************************************_CLOCK_FREQUENCY_USED_************************************/
#define XTAL_FREQ								16

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum timerError{
	TIMER_OK,
	WRONG_TIMER_USED,
	WRONG_DESIRED_TIME
	}en_timerError_t;


/**

Initializes a timer in the microcontroller based on the specified timer number and operating mode.
u8_a_timerUsed The timer number to initialize (TIMER_0, TIMER_1, or TIMER_2).
en_timerError_t Returns TIMER_OK if initialization was successful, and WRONG_TIMER_USED if the specified timer is not supported.
This function sets the timer mode (OV_TIMER or CTC_TIMER) according to pre-defined constants,
and sets the corresponding timer control registers (TCCR0, TCCR1A/B, TCCR2) accordingly.
If the timer is TIMER_0 or TIMER_2 and the mode is OV_TIMER, the function configures the timer in Normal Mode and enables the overflow interrupt.
If the mode is CTC_TIMER, the function configures the timer in CTC Mode and enables the compare match interrupt.
If the timer is TIMER_1, the function does not perform any initialization and returns immediately with the TIMER_OK status.
the function enables the global interrupt flag, allowing interrupt requests to be serviced by the microcontroller's interrupt service routine.
*/
en_timerError_t TIMER_init(u8 u8_a_timerUsed);
/*

 This function sets the desired time in milliseconds for a specific timer and mode.
 u8_a_timerUsed Timer to be used (TIMER_0, TIMER_1, or TIMER_2).
 u32_a_desiredTime Desired time in milliseconds.
 en_timerError_t Returns TIMER_OK if successful, or WRONG_TIMER_USED if the selected timer is not available.
*/

en_timerError_t TIMER_setTime(u8 u8_a_timerUsed, u32 u32_a_desiredTime);
/**
 * Sets the prescaler value for the specified timer and starts the timer.
 * This function sets the prescaler value for the specified timer and starts the timer. The prescaler value
 * determines the frequency at which the timer increments its value. This function only supports TIMER0 and
 * TIMER2. TIMER1 is not supported. The supported prescaler values are: 1, 8, 64, 256, and 1024.
 * timer  The timer to be started. Must be either TIMER0 or TIMER2.
 * error  Error code indicating the success or failure of the function.               
 */
en_timerError_t TIMER_start(u8 u8_a_timerUsed);
/* This function stops a timer according to the selected timer number.
*u8_a_timerUsed: The timer to be stopped.
*en_error: Error code indicating the success or failure of the function.
*/
en_timerError_t TIMER_stop(u8 u8_a_timerUsed);
/**
 *This function sets the duty cycle of a PWM signal for TIMER0.
 *u8_a_timerUsed: The timer to be used. TIMER0 is the only timer supported.
 *u32_a_desiredDutyCycle: The desired duty cycle for the PWM signal (between 0 and 100).
 *en_error: Error code indicating the success or failure of the function.
 */
en_timerError_t TIMER_pwmGenerator(u8 u8_a_timerUsed, u32 u32_a_desiredDutyCycle);
/*
 *This function sets a function to be called when a timer interrupt occurs.
 *u8_a_timerUsed: The timer to be used.
 *funPtr: Pointer to the function to be called when a timer interrupt occurs.
 *return None.
*/
void			TIMER_setCallBack(u8 u8_a_timerUsed, void (*funPtr)(void));
/*
 * Disables the interrupt for the specified timer.
 *
 *  u8_a_timerUsed The timer to stop the interrupt for (TIMER_0, TIMER_1, or TIMER_2).
 *
 *  en_timerError_t Returns TIMER_OK if the operation was successful, or WRONG_TIMER_USED if an invalid timer is specified.
 */
en_timerError_t	TIMER_stopInterrupt(u8 u8_a_timerUsed);
/*
 *Delays the program for the specified time using the specified timer.
 *u8_a_timerUsed The timer to use for the delay (TIMER_0, TIMER_1, or TIMER_2).
 *u32_a_timeInMS The time to delay the program in milliseconds. en_timerError_t Returns TIMER_OK if the operation was successful, or WRONG_TIMER_USED if an invalid timer is specified.
 */
en_timerError_t TIMER_delay(u8 u8_a_timerUsed, u32 u32_a_timeInMS);

/*
 * Enables the interrupt for the specified timer.
 *
 *  u8_a_timerUsed The timer to stop the interrupt for (TIMER_0, TIMER_1, or TIMER_2).
 *
 *  en_timerError_t Returns TIMER_OK if the operation was successful, or WRONG_TIMER_USED if an invalid timer is specified.
 */

en_timerError_t	TIMER_enableInterrupt(u8 u8_a_timerUsed);




#endif /* TIMER_H_ */