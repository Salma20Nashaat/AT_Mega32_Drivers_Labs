/*
 * GccApplication18.c
 *
 * Created: 9/6/2026 3:20:49 AM
 * Author : ismai
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>
#define F_CPU 1000000UL
#include <avr/io.h>


int main(void)
{
    DDRC = 0b000000001;
    while (1) 
    {
		PORTC =0b00000001;
		_delay_ms(1000);
		PORTC =0b00000000;
		_delay_ms(1000);
    }
}

