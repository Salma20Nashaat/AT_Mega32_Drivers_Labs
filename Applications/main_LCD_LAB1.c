/*
 * GccApplication13.c
 *
 * Created: 9/3/2026 7:18:20 PM
 * Author : ismai
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"

#include "LCD_int.h"
# define F_CPU 1000000UL
#include "util/delay.h"



int main()
{   LCD_void_init();
	while(1)
	{   
		LCD_SendString("SALMA");
		_delay_ms(1000);
		break;
	}
}

