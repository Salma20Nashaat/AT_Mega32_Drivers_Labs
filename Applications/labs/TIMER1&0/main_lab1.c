/*
 * TIMER.c
 *
 * Created: 9/8/2026 5:44:08 PM
 * Author : ismai
 */ 
#define F_CPU 1000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "TIMER_int.h"
#include "INTERRUPT_int.h"
#include "INTERRUPT_private.h"
#include "avr/interrupt.h"
/*#include "avr/io.h"*/
#include "DIO_private.h"

u8 counter = 0;

int main(void)
{  
	DIO_voidSetPinDirection(PORTC,PIN0,OUTPUT);
	 voidTimerInit();
	 initExternalInterupts();
    set_bit(SREG,7);
    while (1) 
    {
		
    }
}

ISR(TIMER0_OVF_vect) 
{
	counter++;
	
	if (counter >= 15) 
	{
		toggle_bit(DPORTC,0);
		counter = 0;
	}
}



