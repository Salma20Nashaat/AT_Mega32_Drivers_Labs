
/*
 * UART_lab1.c
 *
 * Created: 9/9/2026 7:04:06 PM
 * Author : ismai
 */ 
#define F_CPU 1000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "INTERRUPT_int.h"
#include "UART_int.h"
#include  "INTERRUPT_private.h"
#include "DIO_int.h"

u8 data;
int main(void)
{   DIO_voidSetPinDirection(PORTB,PIN0,OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN1,OUTPUT);
	initExternalInterupts();
	void_UartInit();
	set_bit(SREG,7);
    while (1) 
	{   
		data = UART_ReceivData();
		switch(data)
	    {
		    case 1:
		    if(DIO_u8ReadPinValue(PORTB, PIN0) == HIGH)
		    {
			    DIO_voidSetPinValue(PORTB, PIN0, LOW);
		    }
		    else
		    {
			    DIO_voidSetPinValue(PORTB, PIN0, HIGH);
		    }
		    break;
			case 2:
			if(DIO_u8ReadPinValue(PORTB, PIN1) == HIGH)
			{
				DIO_voidSetPinValue(PORTB, PIN1, LOW);
			}
			else
			{
				DIO_voidSetPinValue(PORTB, PIN1, HIGH);
			}
			break;
	    }
		
	}
}



