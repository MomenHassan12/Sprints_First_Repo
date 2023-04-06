/*
 * LED_Sequence.c
 *
 * Created: 4/5/2023 6:53:08 AM
 * Author : Speed
 */ 

#include "APPLICATION/APP.h"
int main(void)
{
	APP_initModules();
    while (1) 
    {
		APP_ledSequenceV1();
    }
}

