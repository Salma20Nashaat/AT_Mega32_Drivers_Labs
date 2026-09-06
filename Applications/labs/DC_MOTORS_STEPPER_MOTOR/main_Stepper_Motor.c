/*
 * GccApplication17.c
 *
 * Created: 9/5/2026 6:51:03 PM
 * Author : ismai
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include <util/delay.h>
#define F_CPU 1000000UL

#include "STEPPER_MOTOR_int.h"
#include <avr/io.h>


int main(void)
{
	STEPPER_voidInit();   
    
	while (1)
	{
		FULL_STEP(0);
		_delay_ms(1000);
		FULL_STEP(1);
		_delay_ms(1000);
		HALF_STEP(0);
		_delay_ms(1000);
		HALF_STEP(1);
		_delay_ms(1000);
	}
}

