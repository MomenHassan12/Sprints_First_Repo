/*
 * uart_config.h
 *
 * Created: 5/23/2023 12:40:35 AM
 *  Author: Speed
 */ 


#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_


#define F_CPU        8000000
#define BAUDRATE    BAUDRATE_9600 
#define recive_size  5
#define State_send   0
#define State_recive 1 
#define USART_SET_MODE             USART_ASYNC_MODE


#define USART_SET_PARITY_MODE      USART_DIS_PARITY

#define USART_SET_STOP_BIT         USART_ONE_STOP_BIT

#define USART_SET_DATA_SIZE         USART_DATA_SIZE_8


#define USART_SET_SPEED             USART_NORMAL_SPEED

#define NUMBER_OF_UART_USED			1

#define UART_0						0


#define UART_RECEIVE_BUFFER_SIZE			1024
 #define UART_BUFFER_SIZE                   1024 



#endif /* UART_CONFIG_H_ */