/*
 * APP.h
 *
 * Created: 4/5/2023 9:26:16 AM
 *  Author: Speed
 */ 


#ifndef APP_H_
#define APP_H_
#define F_CPU	16000000UL

#include <util/delay.h>
#include "../ECUAL/BUTTON/Button.h"
#include "../ECUAL/LED/LED.h"
#include "../MCAL/EXT_INT/EXT_INT.h"
#include "../MCAL/TIMER/timer.h"
void APP_initModules(void);
void APP_ledSequenceV3 (void);
void APP_ledUnitTesting (void);





#endif /* APP_H_ */