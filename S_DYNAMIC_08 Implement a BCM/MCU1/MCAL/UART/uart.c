/*
 * uart.c
 *
 * Created: 5/24/2023 2:45:14 AM
 *  Author: Speed
 */
#include "uart.h"

 extern const ST_USART_CONF st_g_USARTconfig [NUMBER_OF_UART_USED];
volatile  Uchar8_t arr_g_recieveBuffer [UART_RECEIVE_BUFFER_SIZE];
 static Uchar8_t buffer_index = 0;
 Uchar16_t g_u16_char_size;
   Uchar16_t g_u16_rx_char_size = 0;

volatile f_g_RX=0;
volatile  f_g_TX=0;
void (*UART_callBack_send) (void) = nullPtr;
void (*UART_callBack_recive) (void) = nullPtr;

EN_UART_status_t UART_init (void)
 {
	 
	 EN_UART_status_t returnValue = UART_OK;
	 Uchar8_t UCSRCValue = 0;
	 uint32_t UBRRValue = 0;


	 switch(st_g_USARTconfig[UART_0].BAUDRATE)
	 {
		 case BAUDRATE_2400:
		 UBRRValue = (F_CPU/((uint32_t)16*2400))-1;
		 UBRRL = UBRRValue;
		 UBRRH = (UBRRValue >> 8);
		 break;
		 
		 case BAUDRATE_4800:
		 UBRRValue = (F_CPU/((uint32_t)16*4800))-1;
		 UBRRL = UBRRValue;
		 UBRRH = (UBRRValue >> 8);
		 break;
		 
		 case BAUDRATE_9600:
		 UBRRValue = (F_CPU/((uint32_t)16*9600))-1;
			 UBRRH = (UBRRValue >> 8);
		 UBRRL = UBRRValue;
	
		 break;
		 
		 
		 default:
		 returnValue = UART_NOK;
		 break;
	 }
	 
	 #if USART_SET_SPEED == USART_NORMAL_SPEED
	 CLEAR_BIT(UCSRA,U2X);
	 #elif USART_SET_SPEED == USART_DOUBLE_SPEED
	 SET_BIT(UCSRA,U2X);
	 #else
	 returnValue = UART_NOK
	 #endif
	 
	 if (st_g_USARTconfig[UART_0].recieverIntState  == UART_RX_INT_ENABLE)
	 {
		 SET_BIT(UCSRB, RXCIE);
	 }
	 else if (st_g_USARTconfig[UART_0].recieverIntState == UART_RX_INT_DISABLE)
	 {
		 CLEAR_BIT(UCSRB, RXCIE);
	 }
	 else
	 {
		 returnValue = UART_NOK;
	 }
	 
	 if (st_g_USARTconfig[UART_0].transmitterIntState == UART_TX_INT_ENABLE)
	 {
		 SET_BIT(UCSRB, TXCIE);
	 }
	 else if (st_g_USARTconfig[UART_0].transmitterIntState == UART_TX_INT_DISABLE)
	 {
		 CLEAR_BIT(UCSRB, TXCIE);
	 }
	 else
	 {
		 returnValue = UART_NOK;
	 }
	 
	 if (st_g_USARTconfig[UART_0].recieverState == UART_RX_ENABLE)
	 {
		 SET_BIT(UCSRB, RXEN);
	 }
	 else if (st_g_USARTconfig[UART_0].recieverState == UART_RX_DISABLE)
	 {
		 CLEAR_BIT(UCSRB, RXEN);
	 }
	 else
	 {
		 returnValue = UART_NOK;
	 }
	 
	 if (st_g_USARTconfig[UART_0].transmitterState == UART_TX_ENABLE)
	 {
		 SET_BIT(UCSRB, TXEN);
	 }
	 else if (st_g_USARTconfig[UART_0].transmitterState == UART_TX_DISABLE)
	 {
		 CLEAR_BIT(UCSRB, TXEN);
	 }
	 else
	 {
		 returnValue = UART_NOK;
	 }
	 
	 #if USART_SET_MODE == USART_ASYNC_MODE
	 CLEAR_BIT(UCSRCValue,UMSEL);
	 #elif USART_SET_MODE == UART_SYNCHRONOUS
	 SET_BIT(UCSRCValue,UMSEL);
	 #else
	 returnValue = UART_NOK
	 #endif
	 
	 #if USART_SET_PARITY_MODE == USART_DIS_PARITY
	 CLEAR_BIT(UCSRCValue,UPM1);	CLEAR_BIT(UCSRCValue,UPM0);
	 #elif USART_SET_PARITY_MODE == USART_EVEN_PARITY
	 SET_BIT(UCSRCValue,UPM1);	CLEAR_BIT(UCSRCValue,UPM0);
	 #elif USART_SET_PARITY_MODE == USART_ODD_PARITY
	 SET_BIT(UCSRCValue,UPM1);	SET_BIT(UCSRCValue,UPM0);
	 #else
	 returnValue = UART_NOK
	 #endif
	 
	 #if USART_SET_STOP_BIT == USART_ONE_STOP_BIT
	 CLEAR_BIT(UCSRCValue,USBS);
	 #elif USART_SET_STOP_BIT == USART_TWO_STOP_BITS
	 SET_BIT(UCSRCValue,USBS);
	 #else
	 returnValue = UART_NOK
	 #endif
	 
	 switch(st_g_USARTconfig[UART_0].DATASIZE)
	 {
		 case USART_DATA_SIZE_5:
		 CLEAR_BIT(UCSRCValue,UCSZ2);	CLEAR_BIT(UCSRCValue,UCSZ1);	CLEAR_BIT(UCSRCValue,UCSZ0);
		 break;
		 
		 case USART_DATA_SIZE_6:
		 CLEAR_BIT(UCSRCValue,UCSZ2);	CLEAR_BIT(UCSRCValue,UCSZ1);	SET_BIT(UCSRCValue,UCSZ0);
		 break;
		 
		 case USART_DATA_SIZE_7:
		 CLEAR_BIT(UCSRCValue,UCSZ2);	SET_BIT(UCSRCValue,UCSZ1);	CLEAR_BIT(UCSRCValue,UCSZ0);
		 break;
		 
		 case USART_DATA_SIZE_8:
		 CLEAR_BIT(UCSRCValue,UCSZ2);	SET_BIT(UCSRCValue,UCSZ1);	SET_BIT(UCSRCValue,UCSZ0);
		 break;
		 
		 case USART_DATA_SIZE_9:
		 SET_BIT(UCSRCValue,UCSZ2);	SET_BIT(UCSRCValue,UCSZ1);	SET_BIT(UCSRCValue,UCSZ0);
		 break;
		 
		 default:
		 returnValue = UART_NOK;
		 break;
	 }
	 
	 if (returnValue == UART_OK)
	 {
		 SET_BIT(UCSRCValue,URSEL);
		 UCSRC = UCSRCValue;
	 }
	 else
	 {
		 /*DO NOTHING*/
	 }
	 
	 SET_BIT(SREG, Ibit);
	 
	 return returnValue;
 }
 
EN_UART_status_t UART_deinit (void)
 {
	 EN_UART_status_t returnValue = UART_OK;
	 UCSRB = 0;
	 return returnValue;
 }
 
 EN_UART_status_t UART_sendByte (Uchar8_t u8_a_byte)
 {
	 EN_UART_status_t returnValue = UART_OK;
	g_u16_char_size = 0;
	
	UDR = u8_a_byte;


	 return returnValue;
}
 EN_UART_status_t UART_sendString (Uchar8_t * str , Uchar16_t u16_arr_size)
 {
	 EN_UART_status_t returnValue = UART_OK;
	g_u16_char_size = u16_arr_size;
	strcpy(arr_g_recieveBuffer, str);
	UDR= arr_g_recieveBuffer[buffer_index];

	 return returnValue;
 }
 

  void uart_recive(Uchar16_t  u16_arr_size)
  {
	  g_u16_rx_char_size = 5;
  }
void uart_recive_callback()
{ 	
f_g_RX;
}
void uart_send_callback()
{
f_g_TX;
}

 EN_UART_status_t UART_setCallBack (Uchar8_t state,void (*ptr_func)(void))
 {
		if(ptr_func != nullPtr)
		{
	if (state==State_send)
	{ 
		UART_callBack_send=ptr_func;
		
	}else 
	if(state==State_recive)
		
			{
				UART_callBack_recive = ptr_func;
		}
		
			EN_UART_status_t returnValue = UART_OK;
	 return returnValue;
 }
 
		}

ISR(USART_TXC)
{
	static Uchar16_t u16_size_counter = 1;


	if(u16_size_counter <= g_u16_char_size  && arr_g_recieveBuffer[u16_size_counter] != '\0' )
	{
		UDR = arr_g_recieveBuffer[u16_size_counter];
		u16_size_counter++;
	}
	else
	{f_g_TX=1;

				UART_callBack_send();
		u16_size_counter = 1 ;


	}
	
	
}


ISR(USART_RXC)
{
	if(buffer_index <= g_u16_rx_char_size)
	{
		arr_g_recieveBuffer[buffer_index] = UDR;
		buffer_index++;

	}
	else
	{
		arr_g_recieveBuffer[buffer_index] = '\0' ;
		buffer_index = 0;
		f_g_RX=1;

		UART_callBack_recive();

	}
}