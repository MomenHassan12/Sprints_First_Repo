/*
 * led.c
 *
 * Created: 5/26/2023 4:38:10 PM
 *  Author: Speed
 */ 
#include "led.h"

/**
 * Initializes LED on given port & pin
 * @param ledPort [in] LED Port
 * @param ledPin [in] LED Pin number in ledPort
 */
void LED_init( Uchar8_t ledPin)
{
      DIO_initpinn( ledPin, OUTPUT);
}

/**
 * Turns on LED at given port/pin
 * @param ledPort [in] LED Port
 * @param ledPin [in] LED Pin number in ledPort
 */

void LED_on(Uchar8_t ledPin)
{
    DIO_writepinn( ledPin, HIGH);
}
/**
 * Turns off LED at given port/pin
 * @param ledPort [in] LED Port
 * @param ledPin [in] LED Pin number in ledPort
 */
void LED_off(Uchar8_t ledPin)
{
	 DIO_writepinn( ledPin, LOW);
}


/**
 * Toggles LED at given port/pin
 * @param ledPort [in] LED Port
 * @param ledPin [in] LED Pin number in ledPort
 */
void LED_toggle(Uchar8_t ledPin)
{
   DIO_togglepin( ledPin);
}