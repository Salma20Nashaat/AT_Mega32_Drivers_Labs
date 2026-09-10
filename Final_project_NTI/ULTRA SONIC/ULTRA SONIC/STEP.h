
#ifndef STEPPER_H_
#define STEPPER_H_
#include "STD_TYPES.h"
#include "DIO_int.h"

#include <util/delay.h>
#define STEPPER_PORT   PORTC

#define BLUE_PIN     PIN0
#define PINK_PIN     PIN1
#define YELLOW_PIN   PIN2 
#define ORANGE_PIN   PIN3  


#define CW         0  
#define CCW        1   



void Stepper_Init(void);
void FULL_STEP(u8 Direction,u8 steps);
void HALF_STEP(u8 Direction,u8 steps);


#endif