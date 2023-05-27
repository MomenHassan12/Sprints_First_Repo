/*
 * project.c
 *
 * Created: 5/22/2023 11:15:44 PM
 * Author : Speed
 */
#include "APPLICATION/app.h"
#include <util/delay.h>


int main(void)
{app_init();
    while (1) 
    {
		app_super_loop();
		_delay_ms(100);
  }
}

