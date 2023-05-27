/*
 * linking_config.c
 *
 * Created: 5/23/2023 12:38:35 AM
 *  Author: Speed
 */ 


#include "uart_linking_config.h"
#include "uart_config.h"


  ST_USART_CONF st_g_USARTconfig [NUMBER_OF_UART_USED] =
 {
	 /*	UART_ID,	dataSize,	baudRate,			reciverState,	reciverIntState, 	transmitterState,	transmitterIntState		*/
	 {UART_0,	USART_DATA_SIZE_8,		BAUDRATE_9600,	UART_RX_ENABLE, UART_RX_INT_ENABLE,	UART_TX_ENABLE,	UART_TX_INT_ENABLE},
 };