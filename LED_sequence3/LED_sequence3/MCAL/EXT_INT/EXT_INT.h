/*
 * EXT_INT.h
 *
 * Created: 4/6/2023 5:51:20 AM
 *  Author: Speed
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_
#include "../../SERVICE/STD_TYPES.h"
#include "../../SERVICE/BIT_MATH.h"
#include "../INTERREPT/INTERREPT.h"
#define MCUCSR  (*(volatile uint8_t*)0X54)
#define MCUCR  (*(volatile uint8_t*)0X55)
#define GIFR  (*(volatile uint8_t*)0X5A)
#define GICR  (*(volatile uint8_t*)0X5B)
/*************interrupt registers pin macro*/
#define ISC10 2
#define ISC11 3
#define ISC01 1
#define ISC00 0

#define ISC2  6
#define WDRF  3

#define INT0 6
#define INT1 7
#define INT2 5
#define sei()      __asm__ __volatile__ ("sei" ::)
#define cli()      __asm__ __volatile__ ("cli" ::)



typedef enum{
	EX_INT0=0,
	EX_INT1,
	EX_INT2
}EXInterruptSource_type;

typedef enum extintError{
	EXTINT_OK,
	WRONG_INT_NUMBER
}EN_extintError_t;


typedef enum{
	VALID_INTERRUPT=0,
	INVALID_INTERRUPT,
	VALID_TRIGGER_STATE,
	INVALID_TRIGGER_STATE
}INTERRUPT_ERROR_TYPE;

EN_extintError_t EXTINT_Init (uint8_t intNumber);
void EXTINT_setCallBackInt (uint8_t intNumber, void (*funPtr) (void));
#endif