#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "STD_TYPES.h"
#include "DIO_int.h"

#define ULTRASONIC_PORT PORTD

#define TRIGGER_PIN PIN6
#define ECHO_PIN    PIN2

void ULTRASONIC_voidInit(void);
u16 ULTRASONIC_u16GetDistance(void);

#endif