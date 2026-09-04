#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"

#include "KYPAD_int.h"
#include "SevSegmen_int.h"
# define F_CPU 1000000UL
#include "util/delay.h"


int main()
{   SevSegment_voidInitialize();
    KEYPAD_voidInit();
	while(1)
	{ 
        SevSegment_voidSetValue(KEYPAD_u8GetPressedKey());
		_delay_ms(1000);
		
	}
}



