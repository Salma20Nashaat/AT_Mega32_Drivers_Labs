#define F_CPU 1000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_int.h"
#include <util/delay.h>

void main(void)
{
	SPI_MasterInit();

	while(1)
	{
		SPI_MasterTransmit(1);
		_delay_ms(1000);
		
	}
}