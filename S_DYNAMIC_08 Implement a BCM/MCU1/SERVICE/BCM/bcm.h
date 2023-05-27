/*
 * bcm.h
 *
 * Created: 5/22/2023 11:16:26 PM
 *  Author: Speed
 */ 

#ifndef BCM_H
#define BCM_H

#include "../../COMMON/STD_TYPES.h"
#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/UART/uart.h"
// Define the maximum data length for communication
extern const ST_USART_CONF st_g_USARTconfig ;
#define BCM_MAX_DATA_LENGTH 100
#define  LED0 PINA4 
#define  LED1 PINA5

typedef enum EN_COM_DEVICE{
	UART_DEVICE = 0 ,
	SPI_DEVICE,
	I2C_DEVICE
}EN_COM_DEVICE;

// Define the BCM instance structure
typedef struct {
    EN_COM_DEVICE DEVICE;
	Uchar8_t receive_buffer[BCM_MAX_DATA_LENGTH];
	Uchar16_t receive_length;

} bcm_instance_t;

// Define the system status enumeration
typedef enum {
	BCM_STATUS_SUCCESS,
	BCM_STATUS_ERROR,
	BCM_STATUS_Send_complete,
	BCM_STATUS_Recive_complete,
} bcm_status_t;



// Function prototypes
bcm_status_t bcm_init(bcm_instance_t* bcm_instance);
bcm_status_t bcm_deinit(bcm_instance_t* bcm_instance);
bcm_status_t bcm_send(bcm_instance_t* bcm_instance, Uchar8_t data);
bcm_status_t bcm_send_n(bcm_instance_t* bcm_instance, Uchar8_t* data, Uchar16_t length);
bcm_status_t bcm_dispatcher(bcm_instance_t* bcm_instance);

#endif   /* BCM_H_ */