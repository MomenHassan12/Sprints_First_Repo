/*
 * EXT_INT.h
 *
 * Created: 4/6/2023 5:51:20 AM
 *  Author: Speed
 */ 
#

#ifndef EXT_INT_H_
#define EXT_INT_H_
#include "../../COMMON/standard_types.h"
#include "../../COMMON/bit_math.h"
#include "../interrupts.h"
#define MCUCSR  (*(volatile u8*)0X54)
#define MCUCR  (*(volatile u8*)0X55)
#define GIFR  (*(volatile u8*)0X5A)
#define GICR  (*(volatile u8*)0X5B)
/*************interrupt registers pin macro*/
#define ISC10 2
#define ISC11 3
#define ISC01 1
#define ISC00 0
#define ISC2  6
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

typedef enum{
	LOW_LEVEL=0,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
}TriggerEdge_type;

typedef enum{
	VALID_INTERRUPT=0,
	INVALID_INTERRUPT,
	VALID_TRIGGER_STATE,
	INVALID_TRIGGER_STATE
}INTERRUPT_ERROR_TYPE;

INTERRUPT_ERROR_TYPE EXT_INT_Enable(EXInterruptSource_type interrupt);
INTERRUPT_ERROR_TYPE EXT_INT_Disable (EXInterruptSource_type interrupt);
INTERRUPT_ERROR_TYPE EXT_INT_TriggerEdge (EXInterruptSource_type interrupt, TriggerEdge_type edge );
#endif