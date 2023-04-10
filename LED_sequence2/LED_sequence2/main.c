/*
 * LED_sequence2.c
 *
 * Created: 4/6/2023 5:42:33 AM
 * Author : Speed
 */ 


#include "APPLICATION/APP.h"

 uint8_t  FLAG=0;
int main(void)
{
		APP_initModules();
		APP_ledSequenceV2();
		
    /* Replace with your application code */
    while (1) 
    {
	
    }
}
ISR(EXT_INT_0)
{ FLAG++;
	if(FLAG==1)
	{
		
		LED_on(LED_0_PORT, LED_0_PIN);
		LED_off(LED_1_PORT, LED_1_PIN);
		LED_off(LED_2_PORT, LED_2_PIN);
		LED_off(LED_3_PORT, LED_3_PIN);
		
	}else if(FLAG==2)
	{
		LED_on(LED_0_PORT, LED_0_PIN);
		LED_on(LED_1_PORT, LED_1_PIN);
		LED_off(LED_2_PORT, LED_2_PIN);
		LED_off(LED_3_PORT, LED_3_PIN);
	}else if(FLAG==3)
	{
		LED_on(LED_0_PORT, LED_0_PIN);
		LED_on(LED_1_PORT, LED_1_PIN);
		LED_on(LED_2_PORT, LED_2_PIN);
		LED_off(LED_3_PORT, LED_3_PIN);
	
	}else if(FLAG==4)
	{
		LED_on(LED_0_PORT, LED_0_PIN);
		LED_on(LED_1_PORT, LED_1_PIN);
		LED_on(LED_2_PORT, LED_2_PIN);
		LED_on(LED_3_PORT, LED_3_PIN);
	}else if(FLAG==5)
	{
		LED_off(LED_0_PORT, LED_0_PIN);
		LED_on(LED_1_PORT, LED_1_PIN);
		LED_on(LED_2_PORT, LED_2_PIN);
		LED_on(LED_3_PORT, LED_3_PIN);
		
	}else if(FLAG==6)
	{
		LED_off(LED_0_PORT, LED_0_PIN);
		LED_off(LED_1_PORT, LED_1_PIN);
		LED_on(LED_2_PORT, LED_2_PIN);
		LED_on(LED_3_PORT, LED_3_PIN);
		
	}else if(FLAG==7)
	{
		LED_off(LED_0_PORT, LED_0_PIN);
		LED_off(LED_1_PORT, LED_1_PIN);
		LED_off(LED_2_PORT, LED_2_PIN);
		LED_on(LED_3_PORT, LED_3_PIN);
	}else if(FLAG==8)
	{
		LED_off(LED_0_PORT, LED_0_PIN);
		LED_off(LED_1_PORT, LED_1_PIN);
		LED_off(LED_2_PORT, LED_2_PIN);
		LED_off(LED_3_PORT, LED_3_PIN);
		FLAG=0;
	}
	
	
}

