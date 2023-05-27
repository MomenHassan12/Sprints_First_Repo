/*
 * uart_linking_config.h
 *
 * Created: 5/23/2023 12:39:50 AM
 *  Author: Speed
 */ 
#include "../../COMMON/STD_TYPES.h"
#include "../../COMMON/BIT_MATH.h"
#ifndef UART_LINKING_CONFIG_H_
#define UART_LINKING_CONFIG_H_


 // options for internal clock speed
typedef enum EN_FCPU_SELECTION{
    FCPU1M=0,
    FCPU2M,
    FCPU4M,
    FCPU8M,

}EN_FCPU_SELECTION;

// BAUD rate options
typedef enum EN_BAUDRATE_SELECTION{
    BAUDRATE_2400=0,
    BAUDRATE_4800,
    BAUDRATE_9600,
    BAUDRATE_14400,
    

}EN_BAUDRATE_SELECTION;
/* USART MODE : 
1-USART_ASYNC_MODE
2-USART_SYNC_MODE
*/
typedef enum EN_USART_SET_MODE {
    USART_ASYNC_MODE = 0 ,
    USART_SYNC_MODE
}EN_USART_SET_MODE;            

/* USART PARITY OPTIONS :
1-USART_DIS_PARITY
2-USART_ODD_PARITY
3-USART_EVEN_PARITY
*/
typedef enum EN_USART_SET_PARITY_MODE{
    USART_DIS_PARITY = 0 ,
    USART_ODD_PARITY,
    USART_EVEN_PARITY
}EN_USART_SET_PARITY_MODE;

/* USART STOP BIT OPTIONS :
1-USART_ONE_STOP_BIT
2-USART_TWO_STOP_BITS
*/
typedef enum EN_USART_SET_STOP_BIT {
 USART_ONE_STOP_BIT = 0 ,
 USART_TWO_STOP_BITS
}EN_USART_SET_STOP_BIT;    

/* USART Data SIZE OPTIONS :
1-USART_DATA_SIZE_5
2-USART_DATA_SIZE_6
3-USART_DATA_SIZE_7
4-USART_DATA_SIZE_8
5-USART_DATA_SIZE_9
*/
typedef enum EN_DATASIZE_SELECTION{
    USART_DATA_SIZE_5=0,
    USART_DATA_SIZE_6,
    USART_DATA_SIZE_7,
    USART_DATA_SIZE_8,
    USART_DATA_SIZE_9,

}EN_DATASIZE_SELECTION;


/* USART Speed MODE :
1-USART_NORMAL_SPEED
2-USART_DOUBLE_SPEED
*/
typedef enum  EN_USART_SET_SPEED {

  USART_NORMAL_SPEED = 0,
  USART_DOUBLE_SPEED
}EN_USART_SET_SPEED;            
 
 typedef enum
 {
	 UART_DATA_SIZE = 0,
	 UART_DATA
 }EN_UART_rcvMode_t;

typedef enum
{
	UART_RX_INT_DISABLE = 0,
	UART_RX_INT_ENABLE
}EN_UART_rxInt_t;

typedef enum
{
	UART_TX_INT_DISABLE = 0,
	UART_TX_INT_ENABLE
}EN_UART_txInt_t;


typedef enum
{
	UART_RX_DISABLE = 0,
	UART_RX_ENABLE
}EN_UART_rx_t;


typedef enum
{
	UART_TX_DISABLE = 0,
	UART_TX_ENABLE
}EN_UART_tx_t;

typedef enum
{
	UART_BUFFER_NEMPTY = 0,
	UART_BUFFER_EMPTY
}EN_UART_bufferStatus_t;

typedef enum
{
	UART_RCV_CMPLT,
	UART_RCV_NCMPLT
}EN_UART_rcvStrCmpltFlg_t;

typedef enum
{
	UART_OK = 0,
	UART_SENDING = 1,
	UART_RECIEVE = 1,
	UART_NOK
}EN_UART_status_t;



typedef struct
{
	Uchar8_t			 		uartUsed;
    EN_DATASIZE_SELECTION DATASIZE;
    EN_BAUDRATE_SELECTION BAUDRATE;
	EN_UART_rx_t			recieverState;
	EN_UART_rxInt_t 		recieverIntState;
	EN_UART_tx_t			transmitterState;
	EN_UART_txInt_t 		transmitterIntState;
}ST_USART_CONF;


#endif /* UART_LINKING_CONFIG_H_ */