#define F_CPU 1000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "ADC_H.h"
#include "util/delay.h"

int main(void) {
	
	DIO_voidSetPinDirection(PORTB, PIN5, OUTPUT);
	DIO_voidSetPinDirection(PORTB, PIN6, OUTPUT);
	DIO_voidSetPinDirection(PORTB, PIN7, OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN0,INPUT);

	ADC_Init();

	while (1) {
		
		u16 adcVal = ADC_Read(0);
		
		u32 voltage = (adcVal * 5000UL) / 1023UL;

		DIO_voidSetPinValue(PORTB, PIN5, LOW);
		DIO_voidSetPinValue(PORTB, PIN6, LOW);
		DIO_voidSetPinValue(PORTB, PIN7, LOW);

		if (voltage > 0 && voltage < 1500) {
			DIO_voidSetPinValue(PORTB, PIN5, HIGH);
		}
		else if (voltage >= 1500 && voltage < 3000) {
			DIO_voidSetPinValue(PORTB, PIN6, HIGH);
		}
		else if (voltage >= 3000) {
			DIO_voidSetPinValue(PORTB, PIN7, HIGH);
		}
		_delay_ms(1000);
	}
}