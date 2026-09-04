#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "KEYPAD_int.h"
#include "LCD_int.h"
#include "CALCULATOR_int.h"
#include "CALCULATOR_config.h"

#define F_CPU 1000000UL
#include "util/delay.h"


void Calculator_voidRun(void)
{
	u8 key;
	u8 num1 =0;
	u8 num2 =0;
	u8 result =0;
	u8 operator =0;
	u8 statge =0;
	
	while(1)
	{
		key = KEYPAD_u8GetPressedKey();
		if(key == 255){ continue; }
		if(key <= 9)
		{
			if(statge)
			{
				num2 = num2*10 +key ;
				LCD_void_SendChar(key +'0');
			}
			else
			{
				num1 = num1*10 +key;
				LCD_void_SendChar(key +'0');
			}				
		}
		else if(key == '+' ||key == '-' ||key == '*' ||key == '/' )
		{
			operator = key;
			LCD_void_SendChar(operator);
			statge = 1;
		}
		else if(key == '=')
		{   LCD_void_SendChar(key);
			switch(operator)
			{
				case '+': result = num1 + num2;break;
				case '-': result = num1 - num2;break;
				case '*': result = num1 * num2;break;
				case '/': result = num1 / num2;break;
			}
			 LCD_voidSendNumber(result );
			statge = 0;
			num1 =0;
			num2 =0;
		}
		else if(key == 'C')
		{
			LCD_SendCommand(0b00000001);
			statge = 0;
			num1 =0;
			num2 =0;
			result = 0;
			operator =0;
	    }
		
	}
}
