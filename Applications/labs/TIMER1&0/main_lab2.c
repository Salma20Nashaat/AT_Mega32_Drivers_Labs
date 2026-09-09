#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "TIMER_int.h"
#include "ADC_H.h"
#include <avr/interrupt.h>
#include <avr/io.h>
u8 isr =0;
int main(void)
{
	u16 adc_value = 0;

	DIO_voidSetPinDirection(PORTA, PIN3, OUTPUT);
	DIO_voidSetPinDirection(PORTA, PIN0, INPUT);
	voidTimerInit();
	ADC_Init();
	set_bit(SREG, 7);

	while(1)
	{
		adc_value = ADC_Read(0);
		OCR0 = (u8)(adc_value / 4);
		if(isr==0)
		{
			DIO_voidSetPinValue(PORTB,PIN3,LOW);
			
		}
		else
		{
			DIO_voidSetPinValue(PORTA,PIN3,HIGH);
		}
	}
}

ISR(TIMER0_COMP_vect)
{
	isr = ~isr;
}