#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "TIMER_int.h"
#include "ADC_H.h"
#include "DIO_private.h"
#include <avr/interrupt.h>

volatile u8 counter = 0;

int main(void)
{
	u16 adc_value =0;

	
	DIO_voidSetPinDirection(PORTD, PIN0,OUTPUT);
	DIO_voidSetPinDirection(PORTD, PIN1,OUTPUT);
	DIO_voidSetPinDirection(PORTD, PIN2,OUTPUT);
	
	DIO_voidSetPinDirection(PORTA, PIN0,INPUT);

	voidTimerInit();
	ADC_Init();
	set_bit(SREG,7);

	

	while(1)
	{    adc_value = ADC_Read(0);
		OCR0 = (u8)(adc_value / 4);
	}
}

ISR(TIMER0_COMP_vect)
{
	counter++;
	
	if (counter >= 50)
	{
		toggle_bit(DPORTD,0);
		toggle_bit(DPORTD,1);
		toggle_bit(DPORTD,1);
		counter = 0;
	}
}