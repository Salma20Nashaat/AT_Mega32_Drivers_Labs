#include <avr/io.h>
#include "STEP.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"

static const u8 FullStep_Array[5] = {
0b00001001,
0b00000011,
0b00000110,
0b00001100,
0b00001001,
};


static const u8 HalfStep_Array[9] = {
	0b00001001,
	0b00000001,
	0b00000011,
	0b00000010,
	0b00000110,
	0b00000100,
	0b00001100,
	0b00001000,
	0b00001001,
};

void Stepper_Init(void) {
	
	DIO_voidSetPinDirection(STEPPER_PORT,  BLUE_PIN, OUTPUT);
	DIO_voidSetPinDirection(STEPPER_PORT, PINK_PIN, OUTPUT);
	DIO_voidSetPinDirection(STEPPER_PORT, YELLOW_PIN, OUTPUT);
	DIO_voidSetPinDirection(STEPPER_PORT,ORANGE_PIN , OUTPUT);
}


void FULL_STEP(u8 Direction,u8 steps)
{
	if(Direction == CW)
	{
			for(u8 i = 0; i < steps; i++)
			{
				DIO_voidSetPortValue(STEPPER_PORT, FullStep_Array[i]);
				_delay_ms(1000);
			}
		
	}

	else if(Direction == CCW)
	{
			for(s8 i = steps; i >= 0; i--)
			{
				DIO_voidSetPortValue(STEPPER_PORT, FullStep_Array[i]);
				_delay_ms(1000);
			}
		
	}
}
void HALF_STEP(u8 Direction,u8 steps)
{
	if(Direction == CW)
	{
		for(u8 i=0; i< steps;i++){
			
				DIO_voidSetPortValue(STEPPER_PORT,HalfStep_Array [i]);
			_delay_ms(1000);
		}
	
	}
	else if(Direction == CCW)
	{
		for(u8 i=steps; i>= 0;i--){
			
				DIO_voidSetPortValue(STEPPER_PORT, HalfStep_Array[i]);
		
			_delay_ms(1000);
		}
		
	}
	else
	{
		
	}
}