/*
 * APP.c
 *
 * Created: 4/5/2023 9:26:30 AM
 *  Author: Speed
*/

#include "APP.h"
u32 onTime=0 ;
u32 offTime=0;
u8  FLAG=0;
u8  BlinkMode = 0;
void APP_initModules(void)
{
DIO_init(PORT_D,2,INPUT);
DIO_write(PORT_D,2,HIGH);
DIO_init(PORT_D,3,INPUT);
DIO_write(PORT_D,3,HIGH);
LED_init(LED_0_PORT, LED_0_PIN);
LED_init(LED_1_PORT, LED_1_PIN);
LED_init(LED_2_PORT, LED_2_PIN);
LED_init(LED_3_PORT, LED_3_PIN);

sei();
EXT_INT_TriggerEdge(EX_INT0,RISING_EDGE);
EXT_INT_Enable(EX_INT0);
EXT_INT_TriggerEdge(EX_INT1,RISING_EDGE);
EXT_INT_Enable(EX_INT1);
TIMER_init(TIMER_2);
TIMER_start(TIMER_2);
}

void APP_ledUnitTesting (void)
{
LED_on(LED_1_PORT,LED_1_PIN);
}

void APP_ledSequenceV3 (void)
  {
if(FLAG==1)
{
	
	LED_on(LED_0_PORT, LED_0_PIN);
	LED_off(LED_1_PORT, LED_1_PIN);
	LED_off(LED_2_PORT, LED_2_PIN);
	LED_off(LED_3_PORT, LED_3_PIN);
	//TIMER_delay(TIMER_2,onTime);
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
if (BlinkMode>0)
{ 
	TIMER_delay(TIMER_2,onTime);
	LED_off(LED_0_PORT, LED_0_PIN);
	LED_off(LED_1_PORT, LED_1_PIN);
	LED_off(LED_2_PORT, LED_2_PIN);
	LED_off(LED_3_PORT, LED_3_PIN);
	TIMER_delay(TIMER_2,offTime);
	
	
}
  }
  
  ISR(EXT_INT_0)
  { 
	  FLAG++;
  }

  ISR(EXT_INT_1)
  {
		BlinkMode++;
		if (BlinkMode == 1)
		{
			onTime = 100;
			offTime = 900;
		}
		else if (BlinkMode == 2)
		{
			onTime = 200;
			offTime = 800;
		}
		else if (BlinkMode == 3)
		{
			onTime = 300;
			offTime = 700;
		}
		else if (BlinkMode == 4)
		{
			onTime = 500;
			offTime = 500;
		}
		else if (BlinkMode == 5)
		{
			onTime = 800;
			offTime = 200;
		}
		else
		{
			BlinkMode = 0;
		}
  }