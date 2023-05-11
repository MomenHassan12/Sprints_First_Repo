/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *-------------------------------------------------------------------------------------------------------------------
 *		   @Date:  	11/5/2023
 *		   @File:  	uartlcfg.c         
 *		 @Module:  	UART
 *		 @Author:	Momen Hassan
 *  @Description:  	Implementation file for UART module     
 *  
 *********************************************************************************************************************/

#ifndef USART_LINKING_H_
#define USART_LINKING_H_


typedef enum EN_FCPU_SELECTION{
	FCPU1=0,
	FCPU2,
	FCPU4,
	FCPU8,

}EN_FCPU_SELECTION;

typedef enum EN_BAUDRATE_SELECTION{
	BAUDRATE_2400=0,
	BAUDRATE_4600,
	BAUDRATE_9600,
}EN_BAUDRATE_SELECTION;


typedef enum EN_DATASIZE_SELECTION{
	USART_DATA_SIZE_5=0,
	USART_DATA_SIZE_6,
	USART_DATA_SIZE_7,
	USART_DATA_SIZE_8,
	USART_DATA_SIZE_9,

}EN_DATASIZE_SELECTION;


typedef struct ST_USART_CONF{
	EN_FCPU_SELECTION FCPU;
	EN_BAUDRATE_SELECTION BAUDRATE;
	EN_DATASIZE_SELECTION DATASIZE;
}ST_USART_CONF;



#endif