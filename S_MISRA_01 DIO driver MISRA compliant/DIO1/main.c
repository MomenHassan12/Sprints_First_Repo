/*
 * DIO1.c
 *
 * Created: 6/6/2023 1:58:37 AM
 * Author : Momen Hassan
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

