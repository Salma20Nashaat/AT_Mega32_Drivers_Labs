#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include <util/delay.h>
#define F_CPU 1000000UL

#include "STEPPER_MOTOR_config.h"
#include "STEPPER_MOTOR_int.h"
u8 STEPPER_FullStep[4]= {
	0b00000001,
	0b00000010,
	0b00000100,
	0b00001000
};
u8 	STEPPER_HalfStep[8]= {
	0b00001001,
	0b00000001,
	0b00000011,
	0b00000010,
	0b00000110,
	0b00000100,
	0b00001100,
	0b00001000
	
};
void STEPPER_voidInit(void)
{
	
	DIO_voidSetPortDirection(STEPPER_PORT,0b00001111);
	
}

void FULL_STEP(u8 Direction)
{
	if(Direction == 1)
	{
		for(u8 i=0; i< 4;i++){
			DIO_voidSetPortValue(STEPPER_PORT, STEPPER_FullStep[i]);
			_delay_ms(200);
		}
	}
	else if(Direction == 0)
	{
		for(s8 i=3; i>=0;i--){
			DIO_voidSetPortValue(STEPPER_PORT, STEPPER_FullStep[i]);
			_delay_ms(200);
		}
	}
	else
	{
		
	}
}

void HALF_STEP(u8 Direction)
{
	if(Direction == 1)
	{
		for(u8 i=0; i< 8;i++){
			DIO_voidSetPortValue(STEPPER_PORT, STEPPER_HalfStep[i]);
			_delay_ms(200);
		}
		
	}
	else if(Direction == 0)
	{
		for(s8 i=7; i>=0;i--){
			DIO_voidSetPortValue(STEPPER_PORT, STEPPER_HalfStep[i]);
			_delay_ms(200);
		}
	}
	else
	{
		
	}
}