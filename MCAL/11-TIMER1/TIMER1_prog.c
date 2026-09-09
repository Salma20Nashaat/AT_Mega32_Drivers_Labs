#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER1_int.h"
#include "TIMER1_private.h"

void voidTimer1Init(void)
{

	clr_bit(TCCR1A, TCCR1A_WGM10);
	set_bit(TCCR1A, TCCR1A_WGM11);
	set_bit(TCCR1B, TCCR1B_WGM12);
	set_bit(TCCR1B, TCCR1B_WGM13);
	
	set_bit(TCCR1A, TCCR1A_COM1A1);
	clr_bit(TCCR1A, TCCR1A_COM1A0);
	
	clr_bit(TCCR1B, TCCR1B_CS12);
	set_bit(TCCR1B, TCCR1B_CS11);
	clr_bit(TCCR1B, TCCR1B_CS10);

	ICR1L =(u8)2499;
	ICR1H =(u8)(2499>>8);
}

void Timer1ServoAngel(u8 angle)
{
	u16 ocr_value = 125 ;
	switch(angle)
	{
		case 0:
		ocr_value =125; break;
		case 90:
		ocr_value =187; break;
		case 180:
		ocr_value =250; break;
		default:
		ocr_value =125; break;
	}
	OCR1AL = (u8)ocr_value;
	OCR1AH = (u8)(ocr_value>>8);
}
