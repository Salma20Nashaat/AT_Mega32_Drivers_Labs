#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "TIMER1_private.h"
#include "TIMER1_int.h"
#include <util/delay.h>

int main(void)
{
	DIO_voidSetPinDirection(PORTD, PIN5, OUTPUT);
	voidTimer1Init();

	while(1)
	{
		Timer1ServoAngel(90);
		
	}
}