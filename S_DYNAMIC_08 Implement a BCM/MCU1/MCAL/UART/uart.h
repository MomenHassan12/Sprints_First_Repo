/*
 * uart.h
 *
 * Created: 5/24/2023 3:52:11 AM
 *  Author: Speed
 */ 
#include "../../COMMON/interrupts.h"
#include "uart_config.h"
#include "uart_linking_config.h"
#include "uart_private.h"

#ifndef UART_H_
#define UART_H_

 EN_UART_status_t UART_init (void);
 EN_UART_status_t UART_deinit (void);
 EN_UART_status_t UART_recieveByte (Uchar8_t byte);
 EN_UART_status_t UART_setCallBack (Uchar8_t state,void (*ptr_func)(void));
 EN_UART_status_t UART_sendString (Uchar8_t * str , Uchar16_t u16_arr_size);
 void uart_recive_callback();
 void uart_send_callback();
 void uart_recive(Uchar16_t  u16_arr_size);

#endif /* UART_H_ */