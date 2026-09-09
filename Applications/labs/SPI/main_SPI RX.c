#define F_CPU 1000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "SPI_int.h"

int main(void)
{
	SPI_SlaveInit();
	
	DIO_voidSetPinDirection(PORTA, PIN0,OUTPUT);

	u8 received_data = 0;
	DIO_voidSetPinDirection(PORTA, PIN0,OUTPUT);

	while(1)
	{
		
		received_data = SPI_SlaveReceive();

		if(received_data == 1)
		{
			DIO_voidSetPinValue(PORTA,PIN0,HIGH);
		}
		else if(received_data == 0)
		{
			DIO_voidSetPinValue(PORTA,PIN0,LOW);
		}
	}
}