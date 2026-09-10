#ifndef MOTOR_H_
#define MOTOR_H_
#include "STD_TYPES.h"
#define MOTOR_PORT1 PORTD
#define MOTOR_PORT2 PORTB

#include "pwm.h"

void MOTOR_INIT(void);
void FORWARD(u8 pwm);
void BACK(u8 pwm);
void RIGHT(u8 pwm);
void LEFT(u8 pwm);
void STOP(void);



#endif