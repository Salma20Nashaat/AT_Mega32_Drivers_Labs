#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "STD_TYPES.h"
#include "DIO_int.h"
#include "ULTRA.h"

void ULTRASONIC_voidInit(void)
{
	DIO_voidSetPinDirection(ULTRASONIC_PORT, TRIGGER_PIN, OUTPUT);
	DIO_voidSetPinDirection(ULTRASONIC_PORT, ECHO_PIN, INPUT);

	TCCR1A = 0x00;
	TCCR1B = 0x00;
	TCNT1 = 0;
}

u16 ULTRASONIC_u16GetDistance(void)
{
	u32 Time_us;

	DIO_voidSetPinValue(ULTRASONIC_PORT, TRIGGER_PIN, HIGH);
	_delay_us(10);
	DIO_voidSetPinValue(ULTRASONIC_PORT, TRIGGER_PIN, LOW);

	TCNT1 = 0;
	TCCR1B = (1 << CS10);

	while(DIO_u8ReadPinValue(ULTRASONIC_PORT, ECHO_PIN) == LOW)
	{
		if(TCNT1 > 40000)
		{
			TCCR1B = 0x00;
			return 999;
		}
	}

	TCNT1 = 0;

	while(DIO_u8ReadPinValue(ULTRASONIC_PORT, ECHO_PIN) == HIGH)
	{
		if(TCNT1 > 40000)
		{
			TCCR1B = 0x00;
			return 999;
		}
	}

	TCCR1B = 0x00;

	Time_us = TCNT1;

	return (u16)(Time_us / 58.2);
}