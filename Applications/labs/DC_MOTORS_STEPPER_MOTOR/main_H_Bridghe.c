/*
 * GccApplication16.c
 *
 * Created: 9/5/2026 6:36:05 PM
 * Author : ismai
 */ 
#include <util/delay.h>
#define F_CPU 1000000UL
#include <avr/io.h>
#include "DIO_int.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"


int main(void)
{
   DIO_voidSetPortDirection(PORTC,OUTPUT);
    while (1) 
    {   
		DIO_voidSetPortValue(PORTC,0b00000110);
		_delay_ms(2000);
		DIO_voidSetPortValue(PORTC,0b00001001);
		_delay_ms(2000);
		
    }
}

