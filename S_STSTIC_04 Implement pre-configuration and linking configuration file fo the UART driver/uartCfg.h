/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *-------------------------------------------------------------------------------------------------------------------
 *		   @Date:  	11/5/2023
 *		   @File:  	uartCfg.h         
 *		 @Module:  	UART
 *		 @Author:	Momen Hassan
 *  @Description:  	Pre-configuration file for uart module     
 *  
 *********************************************************************************************************************/
#ifndef <UARTCFG_H>
#define <UARTCFG_H>

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "uart.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************_SELECT_PARITY_MODE_**********************************/
/*
 *	TO  SELECT PARITY MODE for uart
 *		option 1 			-> 		UART_PARITY_EVEN   
 *		option 2 			-> 		UART_PARITY_ODD    
 *		option 3 			-> 		UART_PARITY_DISABLE
 */
#define UART_PARITY_MODE      		UART_PARITY_EVEN



/******************************_SELECT_CHARACTER_SIZE_*******************************/
/*
 *	TO  SELECT CHARACTER SIZE for uart
 *		option 1 			-> 		UART_5_BIT
 *		option 2 			-> 		UART_6_BIT
 *		option 3 			-> 		UART_7_BIT
 *		option 4 			-> 		UART_8_BIT
 *		option 5 			-> 		UART_9_BIT
 */
#define UART_CHARACTER_SIZE			UART_8_BIT



/**********************************_SELECT_MODE_SELECT**********************************/
/*
 *	TO  SELECT MODE SELECT for uart
 *		option 1 			-> 		UART_ASYNCHRONOUS
 *		option 2 			-> 		UART_SYNCHRONOUS
 */
#define UART_MODE_SELECT			UART_ASYNCHRONOUS



/*****************************_SELECT_TANSMISSION_SPEED_********************************/
/*
 *	TO  SELECT PARITY MODE for uart
 *		option 1 			-> 		UART_NORMAL_SPEED   
 *		option 2 			-> 		UART_DOUBLE_SPEED
 */
#define UART_TRANSMISSION_SPEED		UART_NORMAL_SPEED



/**********************************_SELECT_STOP_BIT_************************************/
/*
 *	TO  SELECT PARITY MODE for uart
 *		option 1 			-> 		UART_STOP_1_BIT
 *		option 2 			-> 		UART_STOP_2_BIT
 */
#define UART_STOP_BITS				UART_STOP_1_BIT



/*************************_SYSTEM_OSCILLARTOR_CLOCK_FREQUENCY_/*************************/
/*
 *	Enter microcontrolers frequency in Hz writing UL besides it
 */
#define F_CPU						16000000UL



/**********************************_SELECT_BAUD_RATE_***********************************/
/*
 *	Enter BAUD RATE desired for the uart
 */
#define UART_BAUD_RATE				9600


 
#endif  /* UARTCFG_H */
/**********************************************************************************************************************
 *  END OF FILE: uartCfg.h
 *********************************************************************************************************************/
