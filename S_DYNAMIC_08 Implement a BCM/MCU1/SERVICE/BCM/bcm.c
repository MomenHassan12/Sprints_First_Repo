/*
 * bcm.c
 *
 * Created: 5/22/2023 11:16:14 PM
 *  Author: Speed
 */ 
#include "bcm.h"
#include <util/delay.h>

extern f_g_TX;
extern f_g_RX;
extern bcm_instance_t bcm_config;
 bcm_status_t bcm_init(bcm_instance_t* bcm_instance)
 {
	 bcm_status_t returnerro =BCM_STATUS_SUCCESS;
 switch (bcm_config.DEVICE)
 {
 case UART_DEVICE :
 UART_init();
 	  UART_setCallBack(State_send,uart_send_callback);
 	  UART_setCallBack(State_recive,uart_recive_callback);
 	break;
 case SPI_DEVICE:
 break;
 case I2C_DEVICE:
 break;
 	 default:
 	 returnerro = BCM_STATUS_ERROR;
 }
 			 return returnerro;

 }
 bcm_status_t bcm_deinit(bcm_instance_t* bcm_instance)
 {
	  bcm_status_t returnerro =BCM_STATUS_SUCCESS;
	  switch (bcm_config.DEVICE)
	  {
		  case UART_DEVICE :
		  UART_deinit();
		  break;
		  case SPI_DEVICE:
		  break;
		  case I2C_DEVICE:
		  break;
		  default:
		  returnerro = BCM_STATUS_ERROR;
	  }
	 			 return returnerro;

 }
 bcm_status_t bcm_send(bcm_instance_t* bcm_instance, Uchar8_t data)
 {
	 	  bcm_status_t returnerro =BCM_STATUS_SUCCESS;
		     switch (bcm_config.DEVICE)
		     {
	 case UART_DEVICE :
	 UART_sendByte(data);
	 break;
	 case SPI_DEVICE:
	 break;
	 case I2C_DEVICE:
	 break;
	 default:
	 returnerro = BCM_STATUS_ERROR;
			 }
			 return returnerro;
 }
 bcm_status_t bcm_send_n(bcm_instance_t* bcm_instance, Uchar8_t* data, Uchar16_t length)
 {
  	  bcm_status_t returnerro =BCM_STATUS_SUCCESS;
  	  switch (bcm_config.DEVICE)
  	  {
	  	  case UART_DEVICE :
		UART_sendString(data,length);
	  	  break;
	  	  case SPI_DEVICE:
	  	  break;
	  	  case I2C_DEVICE:
	  	  break;
	  	  default:
	  	  returnerro = BCM_STATUS_ERROR;
  	  }
  	  return returnerro;
    }
  

bcm_status_t bcm_dispatcher(bcm_instance_t* bcm_instance)
{
	  bcm_status_t returnerro =BCM_STATUS_SUCCESS;
	  switch (bcm_config.DEVICE)
	  {

		  case UART_DEVICE :
	
		if (f_g_RX==1)
		{                 _delay_ms(2000);

                 DIO_togglepin(LED0);
                 f_g_RX=0;
		}
		else 
		if (f_g_TX==1)
		{		_delay_ms(2000);

		DIO_togglepin(LED1);
		f_g_TX=0;
		}
		  break;
		  case SPI_DEVICE:
		  break;
		  case I2C_DEVICE:
		  break;
		  default:
		  returnerro = BCM_STATUS_ERROR;
	  }
	  return returnerro;
  }