#define F_CPU 16000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "DIO_private.h"
#include "ADC.h"


int main(void) {
	SERVO_voidInit() ;
	ADC_Init();
	
	u16 adc_digital_value = 0;
	float  vout =0.0;
	
	DIO_voidSetPinDirection(DPORTC, PIN0, OUTPUT);
	DIO_voidSetPinDirection(DPORTC, PIN4, INPUT);
	DIO_voidSetPinValue(DPORTC, PIN4, HIGH);
	while (1) {
		
		if(DIO_u8ReadPinValue(DPORTC,PIN4)==0){
			SERVO_voidSetAngle(90);
			_delay_ms(50);
			SERVO_voidSetAngle(0);
			_delay_ms(50);
		}
		else{
			SERVO_voidSetAngle(0);
		}
		
		
		adc_digital_value = ADC_Read(0);
		
		vout = (adc_digital_value * 5.0) / 1024.0;

		clr_bit(PORTC, PIN0);
		if(vout  <2){ //ldr<456
			set_bit(PORTC, PIN0);
		}
		else{ //ldr>456
			clr_bit(PORTC,PIN0);
		}
		_delay_ms(100);
	}

	return 0;
}