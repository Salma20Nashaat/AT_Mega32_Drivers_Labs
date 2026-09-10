#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "pwm.h"

void PWM_voidInitAllPins(void) {
	// pwm pins in1:in4 
    set_bit(DDRB, PB3);  
    set_bit(DDRD, PD5); 
    set_bit(DDRD, PD4); 
    set_bit(DDRD, PD7); 

    //timer0 fast pwm mode
    set_bit(TCCR0, WGM00); 
    set_bit(TCCR0, WGM01);
	
	//non inverting mode
    set_bit(TCCR0, COM01); 
    clr_bit(TCCR0, COM00);
	
    // Prescaler = 64 
    set_bit(TCCR0, CS01);
    set_bit(TCCR0, CS00);
    clr_bit(TCCR0, CS02);

   //Timer1 for PD4,PD5
     //FAST MODE 8 BIT
    set_bit(TCCR1A, WGM10); 
    clr_bit(TCCR1A, WGM11);
	
    set_bit(TCCR1B, WGM12);
    clr_bit(TCCR1B, WGM13);
    
   //non inverting mode
    set_bit(TCCR1A, COM1A1); 
    clr_bit(TCCR1A, COM1A0);
	
    set_bit(TCCR1A, COM1B1); 
    clr_bit(TCCR1A, COM1B0);
    
    /* Prescaler = 64 */
    set_bit(TCCR1B, CS11);
    set_bit(TCCR1B, CS10);
    clr_bit(TCCR1B, CS12);

    //Timer2 FOR PD7
     //fast pwm mode
    set_bit(TCCR2, WGM20); 
    set_bit(TCCR2, WGM21);
	
	//non inverting mode
    set_bit(TCCR2, COM21); 
    clr_bit(TCCR2, COM20);
	
    // Prescaler = 64 
    set_bit(TCCR2, CS22);
    clr_bit(TCCR2, CS21);
    clr_bit(TCCR2, CS20);
	 
}



void PWM_voidSetTimer0(u8 Value) {
	 

    OCR0 = Value;
  
}

void PWM_voidSetTimer1A(u8 Value) {
	 
    OCR1A = Value;
    
}

void PWM_voidSetTimer1B(u8 Value) {

    OCR1B = Value;
    
}

void PWM_voidSetTimer2(u8 Value) {

    OCR2 = Value;
    
}