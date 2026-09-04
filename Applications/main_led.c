/*main*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "LED_int.h"
#define F_CPU 1000000
#include <util/delay.h>

int main(void)
{
	DIO_voidIntinitialization();
	LED_voidInitialize();

	while(1)
	{
		LED_voidToggle(LED);
		_delay_ms(1000);
	}
	return 0;
}