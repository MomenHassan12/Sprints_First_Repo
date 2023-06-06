/*
 * APP.c
 *
 * Created: 4/5/2023 9:26:30 AM
 *  Author: Speed
*/

#include "APP.h"

void APP_initModules(void)
{
BUTTON_init(BUTTON_0_PORT, BUTTON_0_Pin);
LED_init(LED_0_PORT, LED_0_PIN);
LED_init(LED_1_PORT, LED_1_PIN);
LED_init(LED_2_PORT, LED_2_PIN);
LED_init(LED_3_PORT, LED_3_PIN);
LED_off(LED_0_PORT, LED_0_PIN);
LED_off(LED_1_PORT, LED_1_PIN);
LED_off(LED_2_PORT, LED_2_PIN);
LED_off(LED_3_PORT, LED_3_PIN);
}

void APP_ledUnitTesting (void)
{
LED_on(LED_1_PORT,LED_1_PIN);
}

void APP_ledSequenceV1 (void)
  {
	  static u8 counter =0;
	  static u8 buttonState = 0;
  BUTTON_read(BUTTON_0_PORT, BUTTON_0_Pin, &buttonState);
_delay_ms(100);
  if(buttonState){
	  counter ++;
_delay_ms(100);

  }
  if(counter ==1){
LED_on(LED_0_PORT, LED_0_PIN);
LED_off(LED_1_PORT, LED_1_PIN);
LED_off(LED_2_PORT, LED_2_PIN);
LED_off(LED_3_PORT, LED_3_PIN);

	  }else if(counter ==2){

LED_on(LED_0_PORT, LED_0_PIN);
LED_on(LED_1_PORT, LED_1_PIN);
LED_off(LED_2_PORT, LED_2_PIN);
LED_off(LED_3_PORT, LED_3_PIN);
	  }else if(counter ==3){
LED_on(LED_0_PORT, LED_0_PIN);
LED_on(LED_1_PORT, LED_1_PIN);
LED_on(LED_2_PORT, LED_2_PIN);
LED_off(LED_3_PORT, LED_3_PIN);
	  }else if (counter ==4){
LED_on(LED_0_PORT, LED_0_PIN);
LED_on(LED_1_PORT, LED_1_PIN);
LED_on(LED_2_PORT, LED_2_PIN);
LED_on(LED_3_PORT, LED_3_PIN);
	  }else if (counter ==5){
LED_off(LED_0_PORT, LED_0_PIN);
LED_on(LED_1_PORT, LED_1_PIN);
LED_on(LED_2_PORT, LED_2_PIN);
LED_on(LED_3_PORT, LED_3_PIN);
	  }else if (counter ==6){
LED_off(LED_0_PORT, LED_0_PIN);
LED_off(LED_1_PORT, LED_1_PIN);
LED_on(LED_2_PORT, LED_2_PIN);
LED_on(LED_3_PORT, LED_3_PIN);
  }
  else if (counter ==7){
LED_off(LED_0_PORT, LED_0_PIN);
LED_off(LED_1_PORT, LED_1_PIN);
LED_off(LED_2_PORT, LED_2_PIN);
LED_on(LED_3_PORT, LED_3_PIN);
	  }else if (counter ==8){
LED_off(LED_0_PORT, LED_0_PIN);
LED_off(LED_1_PORT, LED_1_PIN);
LED_off(LED_2_PORT, LED_2_PIN);
LED_off(LED_3_PORT, LED_3_PIN);
counter=0;
	  }



  }