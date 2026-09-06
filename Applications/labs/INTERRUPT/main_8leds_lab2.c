#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include "DIO_int.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "INTERRUPT_int.h"
#include <util/delay.h>

u8 mode_flag = 0;

int main(void)
{
	DIO_voidSetPortDirection(PORTC, 0b11111111);
	
	DIO_voidSetPinDirection(PORTD, PIN2, INPUT);
	DIO_voidSetPinValue(PORTD, PIN2, HIGH);

	initExternalInterupts();
	set_bit(SREG, 7);

	while (1)
	{
		if (mode_flag == 0)
		{
			for(u8 i = 0; i < 8; i++)
			{
				if(mode_flag != 0) break;
				DIO_voidSetPinValue(PORTC, i, HIGH);
				_delay_ms(200);
			}
			for(u8 i = 0; i < 8; i++)
			{
				if(mode_flag != 0) break;
				DIO_voidSetPinValue(PORTC, i, LOW);
				_delay_ms(200);
			}
		}
		else
		{
			for(s8 i = 7; i >= 0; i--)
			{
				if(mode_flag == 0) break;
				DIO_voidSetPinValue(PORTC, i, HIGH);
				_delay_ms(200);
			}
			for(s8 i = 7; i >= 0; i--)
			{
				if(mode_flag == 0) break;
				DIO_voidSetPinValue(PORTC, i, LOW);
				_delay_ms(200);
			}
		}
	}
}


ISR(INT0_vect)
{
	mode_flag = ~mode_flag;
}