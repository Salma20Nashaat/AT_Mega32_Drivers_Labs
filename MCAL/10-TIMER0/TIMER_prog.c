#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "TIMER_private.h"
#include "TIMER_int.h"


void voidTimerInit(void)
{
	clr_bit(TCCR0,TCCR0_WGM00);
	set_bit(TCCR0,TCCR0_WGM01);
	
	clr_bit(TCCR0,TCCR0_CS00);
	clr_bit(TCCR0,TCCR0_CS01);
	set_bit(TCCR0,TCCR0_CS02);

	/* set_bit(TIMSK,TIMSK_TOIE0);*/
	set_bit(TIMSK,TIMSK_OCIE0 );
	OCR0 = 250;
}