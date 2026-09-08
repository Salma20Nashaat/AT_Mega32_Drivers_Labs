#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "ADC_H.h"
#include "LCD_int.h"

#define F_CPU 8000000UL
#include <util/delay.h>

void main(void) {

	ADC_Init ();
	LCD_void_init();
	
	
	DIO_voidSetPinDirection(PORTB, PIN5, OUTPUT);

	u32 v_in = 5000;
	u32 r_known = 1000;
	u32 ldr_resistance = 0;


	while(1) {
		
		u32 ADC_value = ADC_Read(0);

		u32 volt = (ADC_value * v_in) / 1023UL;

		ldr_resistance = ((u32)r_known * v_in - r_known * volt) / volt;

		LCD_void_GoToXY(0,0);
		LCD_Send_String("Resistance: ");
		LCD_void_SendNumber(ldr_resistance);
		LCD_Send_String(" ohm  ");
		if (ldr_resistance > 1000) {
			
			DIO_voidSetPinValue(PORTB, PIN5,HIGH);
		} else
		{
			
			DIO_voidSetPinValue(PORTB, PIN5,LOW);
		}
	}
}