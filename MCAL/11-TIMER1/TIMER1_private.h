#ifndef TIMER1_PRIVATE_H
#define TIMER1_PRIVATE_H

#define TCCR1A   (*(volatile u8*)0x4F)
#define TCCR1B   (*(volatile u8*)0x4E)
#define TCNT1H   (*(volatile u8*)0x4D)
#define TCNT1L   (*(volatile u8*)0x4C)
#define ICR1H    (*(volatile u8*)0x47)
#define ICR1L    (*(volatile u8*)0x46)
#define OCR1AH   (*(volatile u8*)0x4B)
#define OCR1AL   (*(volatile u8*)0x4A)
#define OCR1BH   (*(volatile u8*)0x49)
#define OCR1BL   (*(volatile u8*)0x48)

#define TCCR1A_WGM10  0
#define TCCR1A_WGM11  1
#define TCCR1A_COM1A0 6
#define TCCR1A_COM1A1 7

#define TCCR1B_WGM12  3
#define TCCR1B_WGM13  4
#define TCCR1B_CS10   0
#define TCCR1B_CS11   1
#define TCCR1B_CS12   2

#endif