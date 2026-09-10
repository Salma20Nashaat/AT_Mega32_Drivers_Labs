#include "STD_TYPES.h"
#include "DIO_int.h"
#include "motor.h"

void MOTOR_INIT(void){
	PWM_voidInitAllPins();
	 STOP();
}
void FORWARD(u8 pwm){
	PWM_voidSetTimer0(pwm);//in1
	PWM_voidSetTimer1A(pwm);//in3
    PWM_voidSetTimer1B(0);//in2
	 PWM_voidSetTimer2(0); //in4
}
void BACK(u8 pwm){
	PWM_voidSetTimer0(0);//in1
	PWM_voidSetTimer1A(0);//in3
	PWM_voidSetTimer1B(pwm);//in2
	PWM_voidSetTimer2(pwm);//in4
}
void RIGHT(u8 pwm){
	PWM_voidSetTimer0(pwm);//in1
	PWM_voidSetTimer1A(0);//in3
	PWM_voidSetTimer1B(0);//in2
	PWM_voidSetTimer2(pwm);//in4
}
void LEFT(u8 pwm){
	PWM_voidSetTimer0(0);//in1
	PWM_voidSetTimer1A(pwm);//in3
	PWM_voidSetTimer1B(pwm);//in2
	PWM_voidSetTimer2(0);//in4
	
}
void STOP(){
	PWM_voidSetTimer0(0);//in1
	PWM_voidSetTimer1A(0);//in3
	PWM_voidSetTimer1B(0);//in2
	PWM_voidSetTimer2(0);//in4
	
}
