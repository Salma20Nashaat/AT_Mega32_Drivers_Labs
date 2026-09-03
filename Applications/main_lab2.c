#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h" 


int main(void)
{
    DIO_voidSetPinDirection(PORTC, PIN0 ,OUTPUT);
	DIO_voidSetPinDirection(PORTC, PIN1 ,OUTPUT);
	DIO_voidSetPinDirection(PORTC, PIN2 ,OUTPUT);
	
	DIO_voidSetPortDirection(PORTA, INPUT);
	DIO_voidSetPortValue(PORTA, 0xFF);  
	 

	while(1)
	{
		if (DIO_u8ReadPinValue(PORTA, PIN0) == LOW)
		{
			DIO_voidSetPinValue(PORTC, PIN0, HIGH);
		}
		else
		{
			DIO_voidSetPinValue(PORTC, PIN0, LOW);
		}

		if (DIO_u8ReadPinValue(PORTA, PIN1) == LOW)
		{
			DIO_voidSetPinValue(PORTC, PIN1, HIGH);
		}
		else
		{
			DIO_voidSetPinValue(PORTC, PIN1, LOW);
		}

		if (DIO_u8ReadPinValue(PORTA, PIN2) == LOW)
		{
			DIO_voidSetPinValue(PORTC, PIN2, HIGH);
			
		}
		else
		{
			DIO_voidSetPinValue(PORTC, PIN2, LOW);
		}
		if (DIO_u8ReadPinValue(PORTA, PIN7) == LOW)
		{
			DIO_voidSetPinValue(PORTC, PIN0, HIGH);
			DIO_voidSetPinValue(PORTC, PIN1, HIGH);
			DIO_voidSetPinValue(PORTC, PIN2, HIGH);
			
		}
	}
}