/*main*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
    DIO_voidIntinitialization();

    DIO_voidSetPinDirection(DPORTA, PIN6, INPUT);
    DIO_voidSetPinValue(DPORTC, PIN7, HIGH);

    while(1)
    {
        DIO_voidSetPinValue(DPORTA, PIN7, HIGH);
        _delay_ms(1000);
        DIO_voidSetPinValue(DPORTA, PIN7, LOW);
        _delay_ms(1000);
    }
	return 0;
}