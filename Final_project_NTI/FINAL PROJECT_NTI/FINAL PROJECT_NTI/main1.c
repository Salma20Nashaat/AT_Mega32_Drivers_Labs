#define F_CPU 1000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "KeypadLcd.h"
#include "motor.h"
#include "UART_int.h"
#include "INTERRUPT_int.h"
#include "INTERRUPT_private.h"


int main(void)
{
	 initExternalInterupts();
	 void_UartInit();
	LCD_init();
	keyPad_init();
	MOTOR_INIT();

	u8 speed;
	u8 PWM;
    u8 command;
	speed = GetSpeed();

	PWM = ((u16)speed * 255) / 100;

	LCD_SendCommand(0x01);
	_delay_ms(2);

	LCD_SendString((u8*)"Speed=");
	LCD_SendNumber(speed);

	LCD_SendString((u8*)" PWM=");
	LCD_SendNumber(PWM);
      set_bit(SREG,7);
	while(1)
	{
		if(DIO_u8ReadPinValue(PORTD, PIN3)==0){
		command = UART_ReceivData();

		switch(command)
		{
			case 'F':
			FORWARD(PWM);
			break;

			case 'B':
			BACK(PWM);
			break;

			case 'R':
			RIGHT(PWM);
			break;

			case 'L':
			LEFT(PWM);
			break;

			case 'S':
			STOP();
			break;
		}
		}
		else{
			
		}
	}
}