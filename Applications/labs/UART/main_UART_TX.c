/*
 * UART_lab1.c
 *
 * Created: 9/9/2026 7:04:06 PM
 * Author : ismai
 */ 
#define F_CPU 1000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "INTERRUPT_int.h"
#include "UART_int.h"
#include  "INTERRUPT_private.h"


int main(void)
{
	initExternalInterupts();
	void_UartInit();
	set_bit(SREG,7);
    while (1) 
    {   
		UART_TransmitData(2);
		_delay_ms(100);
		UART_TransmitData(1);
		_delay_ms(100);
	}
}