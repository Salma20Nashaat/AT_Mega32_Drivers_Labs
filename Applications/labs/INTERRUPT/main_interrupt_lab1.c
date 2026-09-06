/*
 * GccApplication19.c
 *
 * Created: 9/6/2026 6:29:07 PM
 * Author : ismai
 */ 

#include "avr/interrupt.h"
#include "DIO_int.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "INTERRUPT_int.h"
#include "DIO_private.h"



int main(void)
{
    DIO_voidSetPinDirection(PORTC,PIN0,OUTPUT);
    DIO_voidSetPinDirection(PORTC,PIN1,OUTPUT);
	
	DIO_voidSetPinDirection(PORTD,PIN2,INPUT);
	DIO_voidSetPinDirection(PORTD,PIN3,INPUT);
	
	DIO_voidSetPinValue(PORTD,PIN2,HIGH);
	DIO_voidSetPinValue(PORTD,PIN3,HIGH);
	
	initExternalInterupts();
	
	set_bit(SREG,7);
	
    while (1) 
    {
		
    }
	
}

ISR(INT0_vect)
{
	toggle_bit(DPORTC,PIN1);
}
ISR(INT1_vect)
{
	toggle_bit(DPORTC,PIN0);
}

