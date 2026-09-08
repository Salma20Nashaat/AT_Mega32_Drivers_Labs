#define F_CPU 1000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "ADC_H.h"
#include "LCD_int.h"


int main(void) {
	
	DIO_voidSetPinDirection(PORTB, PIN5, OUTPUT);
	DIO_voidSetPinDirection(PORTB, PIN6, OUTPUT);
	DIO_voidSetPinDirection(PORTB, PIN7, OUTPUT);


	LCD_void_init();
	ADC_Init();

	LCD_void_GoToXY(0, 0);
	LCD_Send_String("Voltage Voltmeter");

	while (1) {
		
		u32 ADC_value = ADC_Read(0);
		u32 volt_mv = (ADC_value * 5000UL) / 1023UL;

		
		LCD_void_GoToXY(1,0);
		LCD_Send_String("mV: ");
		LCD_void_SendNumber(volt_mv);
		LCD_Send_String(" mV   ");

		
		if (volt_mv > 0 && volt_mv < 1500) {
			DIO_voidSetPinValue(PORTB, PIN5, HIGH);
			DIO_voidSetPinValue(PORTB, PIN6, LOW);
			DIO_voidSetPinValue(PORTB, PIN7, LOW);
		}
		else if (volt_mv >= 1500 && volt_mv < 3000) {
			DIO_voidSetPinValue(PORTB, PIN5, LOW);
			DIO_voidSetPinValue(PORTB, PIN6, HIGH);
			DIO_voidSetPinValue(PORTB, PIN7, LOW);
		}
		else if (volt_mv >= 3000) {
			DIO_voidSetPinValue(PORTB, PIN5, LOW);
			DIO_voidSetPinValue(PORTB, PIN6, LOW);
			DIO_voidSetPinValue(PORTB, PIN7, HIGH);
		}
        _delay_ms(1000);
	}
}