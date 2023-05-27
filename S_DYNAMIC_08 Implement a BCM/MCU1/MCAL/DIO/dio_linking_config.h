/*
 * dio_linking_config.h
 *
 * Created: 5/14/2023 10:30:00 AM
 *  Author: momen
 */ 

#ifndef DIO_LINKING_CONFIG_H
#define DIO_LINKING_CONFIG_H
#include "dio_private.h"

/************* Available Ports ****************/
typedef enum{
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
}EN_dio_port_t;


/************* Available Pins ****************/
typedef enum{
	DIO_PIN0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7
}EN_dio_pin_t;

/************* Available Modes ****************/
typedef enum{
	DIO_MODE_INPUT,
	DIO_MODE_OUTPUT
}EN_dio_mode_t;


/************* Available Values ****************/
typedef enum{
	DIO_HIGH,
	DIO_LOW
}EN_dio_value_t;


/************* Available Pull-up Resistor Settings ****************/
typedef enum{
	DIO_PULLUP_DISABLED,
	DIO_PULLUP_ENABLED
}EN_dio_pullup_t;


/************* DIO Configuration ****************/
typedef struct{
	EN_dio_port_t   dio_port;
	EN_dio_pin_t    dio_pin;
	EN_dio_mode_t   dio_mode;
	EN_dio_value_t  dio_initial_value;
	EN_dio_pullup_t dio_pullup_resistor;
}ST_DIO_ConfigType;



extern ST_DIO_ConfigType DIO_ConfigArray[];



typedef enum{
	PA=0,
	PB,
	PC,
	PD
}EN_DIO_Port_type;

typedef enum{
	OUTPUT,
	INFREE,
	INPULL
}EN_DIO_PinStatus_type;

typedef enum{
	LOW=0,
	HIGH,
}EN_DIO_PinVoltage_type;


typedef enum{
	PINA0=0,
	PINA1=1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS
}EN_DIO_Pin_type;




#endif /* DIO_LINKING_CONFIG_H */