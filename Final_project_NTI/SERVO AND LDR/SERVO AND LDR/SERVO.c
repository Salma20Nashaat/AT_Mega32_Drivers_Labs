#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SERVO.h"

void SERVO_voidInit(void) {
    set_bit(DDRD, PD5);//OC1A
   // fast PWM 
    clr_bit(TCCR1A, WGM10);
    set_bit(TCCR1A, WGM11);
    set_bit(TCCR1B, WGM12);
    set_bit(TCCR1B, WGM13);

    set_bit(TCCR1A, COM1A1);
    clr_bit(TCCR1A, COM1A0);

     ICR1 = 2499;

   // prescaller /8
    clr_bit(TCCR1B, CS10);
    set_bit(TCCR1B, CS11);
    clr_bit(TCCR1B, CS12);
}

void SERVO_voidSetAngle(u8 Angle) {
    u16 Value = 0;

    if (Angle > 180) {
        Angle = 180;
    }

    Value = 125 + (((u32)Angle * 125) / 180);

    OCR1A = Value;
}