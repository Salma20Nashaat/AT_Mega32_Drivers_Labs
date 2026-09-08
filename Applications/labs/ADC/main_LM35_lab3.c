#define F_CPU 1000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "ADC_H.h"
#include "LCD_int.h"

int main(void) {

	DIO_voidSetPinDirection(PORTB, PIN0, OUTPUT);
	DIO_voidSetPinDirection(PORTB, PIN5, OUTPUT);
	DIO_voidSetPinDirection(PORTB, PIN6, OUTPUT);
	DIO_voidSetPinDirection(PORTB, PIN7, OUTPUT);

	LCD_void_init();
	ADC_Init();

	LCD_void_GoToXY(0,0);
	LCD_Send_String("Temp Monitor");

	while (1) {
		
		u32 ADC_value = ADC_Read(0);
        u32 volt = ((u32)ADC_value * 5000UL) / 1023UL;

		u32 temp = volt / 10;

		LCD_void_GoToXY(1, 0);
		LCD_Send_String("Temp: ");
		LCD_void_SendNumber(temp);
		LCD_Send_String(" C   ");

		if (temp < 20) {
			
			DIO_voidSetPinValue(PORTB, PIN0, LOW);
			DIO_voidSetPinValue(PORTB, PIN5, HIGH);
			DIO_voidSetPinValue(PORTB, PIN6, LOW);
			DIO_voidSetPinValue(PORTB, PIN7, LOW);
		}
		else if (temp >= 20 && temp < 40) {
			
			DIO_voidSetPinValue(PORTB, PIN0, LOW);
			DIO_voidSetPinValue(PORTB, PIN5, LOW);
			DIO_voidSetPinValue(PORTB, PIN6,HIGH);
			DIO_voidSetPinValue(PORTB, PIN7, LOW);
		}
		else if (temp >= 40) {
			
			DIO_voidSetPinValue(PORTB, PIN0, HIGH);
			DIO_voidSetPinValue(PORTB, PIN5, LOW);
			DIO_voidSetPinValue(PORTB, PIN6, LOW);
			DIO_voidSetPinValue(PORTB, PIN7, HIGH);
		}
        _delay_ms(500);
	}
}