#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"

#include "LCD_int.h"
#include "LCD_config.h"
# define F_CPU 1000000UL
#include "util/delay.h"


// void LCD_void_init(void)
// 
// {
// 	DIO_voidSetPortDirection(LCD_DATA_PORT, OUTPUT);
// 	DIO_voidSetPortDirection(LCD_CONTROL_PORT, OUTPUT);
// 	
// 	_delay_ms(35);
// 	DIO_voidSetPortValue(LCD_DATA_PORT, 0b00111000);
// 	DIO_voidSetPinValue(LCD_CONTROL_PORT,PIN0,LOW);
// 	DIO_voidSetPinValue(LCD_CONTROL_PORT,PIN1,LOW);
// 	_delay_ms(10);
// 	
// 	DIO_voidSetPortValue(LCD_DATA_PORT, 0b00001111);
// 	
// 	_delay_ms(10);
// 	
// 	DIO_voidSetPortValue(LCD_DATA_PORT, 0b00000001);
// 	
// 	_delay_ms(10);
// 	
// }
void LCD_void_init(void)
{
	DIO_voidSetPortDirection(LCD_DATA_PORT, OUTPUT);

	DIO_voidSetPinDirection(LCD_CONTROL_PORT, LCD_RS_PIN , OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, LCD_RW_PIN , OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, LCD_E_PIN , OUTPUT);

	_delay_ms(40);

	LCD_SendCommand(0b00111000);
	_delay_ms(1);

	LCD_SendCommand(0b00001100);
	_delay_ms(1);

	LCD_SendCommand(0b00000001);
	_delay_ms(2);
}
void LCD_void_SendChar(u8 character)
{   DIO_voidSetPinValue(LCD_CONTROL_PORT,PIN2,HIGH);
	
	DIO_voidSetPinValue(LCD_CONTROL_PORT,PIN0,HIGH);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,PIN1,LOW);
	DIO_voidSetPortValue(LCD_DATA_PORT, character);
	
	DIO_voidSetPinValue(LCD_CONTROL_PORT,PIN2,LOW);
	_delay_ms(5);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,PIN2,HIGH);
	
}
void LCD_SendCommand(u8 command)
{   DIO_voidSetPinValue(LCD_CONTROL_PORT,PIN2,HIGH);
	
	DIO_voidSetPinValue(LCD_CONTROL_PORT,PIN0,LOW);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,PIN1,LOW);
	DIO_voidSetPortValue(LCD_DATA_PORT, command);
	
    DIO_voidSetPinValue(LCD_CONTROL_PORT,PIN2,LOW);
    _delay_ms(5);
    DIO_voidSetPinValue(LCD_CONTROL_PORT,PIN2,HIGH);
	
}
void LCD_SendString(u8*str)
{
	u8 i =0;
	while(str[i] != '\0')
	{
		LCD_void_SendChar(str[i]);
		i++;
		
	}
	
}
void LCD_voidSendNumber(u8 num)
{
	u8 str[4];
	u8 i =0 ;
	if(num == 0)
	{
		LCD_void_SendChar('0');
		return;
	}		
	while( num > 0 && i < 4)
	{
		str[i] =(num % 10)+ '0';;
		num = num /10;
		i++;
	}
	while(i > 0)
	{
		i--;
		LCD_void_SendChar(str[i]);
	}
}

