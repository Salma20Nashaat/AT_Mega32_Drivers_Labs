/* main */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
 
#include "DIO_int.h"
#include "LED_int.h"
#include "SevSegment_int.h"
 
#define F_CPU 8000000UL
#include <util/delay.h>
 
int main(void)
{
    DIO_voidInitialize();
    SevSegment_voidIntinitialize();
 
    while(1)
    {
        SevSegment_voidSetValue(5); 
		_delay_ms(1000);
		SevSegment_voidSetValue(0);
		_delay_ms(1000);
		
    }
 
    return 0;
}