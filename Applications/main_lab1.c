#define F_CPU 1000000
#include <util/delay.h>
#include <avr/io.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"

int main(void)
{
    DDRA = 0b00000010;
    PORTA = 0b00000001;
    while (1)
    {
        if(get_bit(PINA,0) == 0){
            PORTA = 0b00000010;
        }
        else {PORTA = 0b00000000;}
    }
}
