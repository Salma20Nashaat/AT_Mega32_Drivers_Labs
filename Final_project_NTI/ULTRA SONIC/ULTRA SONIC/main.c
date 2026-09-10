#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "STEP.h"

int main(void) {
	u8 distance=0;
	Stepper_Init();
	ULTRASONIC_voidInit();
	while (1) {
		distance=ULTRASONIC_u16GetDistance();
		if(distance<25 && distance>0){
			FULL_STEP(CCW,2);

			_delay_ms(100);
			FULL_STEP(CW,4);

			_delay_ms(100);
		}
		
	}

	return 0;
}