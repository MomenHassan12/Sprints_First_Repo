/*
 * app.c
 *
 * Created: 5/25/2023 6:54:27 PM
 *  Author: Speed
 */ 
#include "app.h"
extern bcm_instance_t bcm_config;

void app_init(void)
{
bcm_init(&bcm_config);

LED_init(LED0);
LED_init(LED1);
}
void app_super_loop()
{
	bcm_dispatcher(&bcm_config);
}


