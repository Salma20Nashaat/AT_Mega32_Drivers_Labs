#include "KeypadLcd.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
u8 key = 0xFF;
u16 speed = 0;
void LCD_init(){
	DIO_voidSetPortDirection(PORTA, 0xFF);
	
	DIO_voidSetPinDirection(PORTB,EN,OUTPUT);
	DIO_voidSetPinDirection(PORTB,RW,OUTPUT);
	DIO_voidSetPinDirection(PORTB,RS,OUTPUT);
	
	_delay_ms(40);
	LCD_SendCommand(0x38);// bit mode_8
	_delay_ms(10);
	LCD_SendCommand(0x0C);//display on / cursor off
	_delay_ms(10);
	LCD_SendCommand(0x01);//clear display
	_delay_ms(20);
}
void LCD_SendCommand(u8 command){
	DIO_voidSetPinValue(PORTB,RS,LOW);//command mode
	DIO_voidSetPinValue(PORTB,RW,LOW);// write  mode
	DIO_voidSetPortValue(PORTA,command);//set COMMAND
	
	DIO_voidSetPinValue(PORTB,EN,HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(PORTB,EN,LOW);
	_delay_ms(1);
}
void LCD_sendChar(u8 Data){
	DIO_voidSetPinValue(PORTB,RS,HIGH);// data mode
	DIO_voidSetPinValue(PORTB,RW,LOW);// write mode
	DIO_voidSetPortValue(PORTA,Data);//set data
	
	DIO_voidSetPinValue(PORTB,EN,HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(PORTB,EN,LOW);
	_delay_ms(5);
}
void LCD_SendNumber(u32 num)
{
	u8 str[11];
	s8 i = 0;
	if (num == 0)
	{
		LCD_sendChar('0');
		return;
	}
	while (num > 0)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	for (i = i - 1; i >= 0; i--)
	{
		LCD_sendChar(str[i]);
	}
}
void LCD_SendString (u8 *str){
	while(*str!='\0'){       //not equal null
		LCD_sendChar(*str);
		str++;
	}
}

u8 arr[4][4]={
	{'7','8','9','/'},
	{'4','5','6','*'},
    {'1','2','3','-'},
	{'C','0','=','+'}
};

void keyPad_init(){
	for(u8 i=PIN4;i<=PIN7;i++){//ROWS
		DIO_voidSetPinDirection(PORTB,i,OUTPUT);
		DIO_voidSetPinValue(PORTB,i,HIGH);
	}
	for(u8 j=PIN4;j<=PIN7;j++){
		DIO_voidSetPinDirection(PORTC,j,INPUT);
		DIO_voidSetPinValue(PORTC,j,HIGH);//PULL UP RESISTANCE
	}
}
u8 keyPadGetKey(){
	u8 row,col,res;
	u8 pressedKEY=0xFF;
	for(row=0;row<4;row++){
		
		DIO_voidSetPinValue(PORTB,row+PIN4,LOW);
		
		for(col=0;col<4;col++){
			
			res=DIO_u8ReadPinValue(PORTC,col+PIN4);
			if(res==LOW){
				_delay_ms(20);
				pressedKEY=arr[row][col];
			
			while(DIO_u8ReadPinValue(PORTC,col+PIN4)==LOW);
			}
		}
		DIO_voidSetPinValue(PORTB,row+PIN4,HIGH);
	}
	return pressedKEY;
}


u8 GetSpeed(void)
{
	u8 key_input;
	u16 temp_speed = 0;

	LCD_SendCommand(0x01);
	_delay_ms(2);

	LCD_SendString((u8*)"Enter Speed:");
	LCD_SendCommand(0xC0);

	while(1)
	{
		key_input = keyPadGetKey();

		if(key_input >= '0' && key_input <= '9')
		{
			u16 new_val = (temp_speed * 10) + (key_input - '0');

			if(new_val <= 100)
			{
				temp_speed = new_val;
				LCD_sendChar(key_input);
			}
		}
		else if(key_input == '=')
		{
			break;
		}
		else if(key_input == 'C')
		{
			temp_speed = 0;

			LCD_SendCommand(0xC0);
			LCD_SendString((u8*)"                ");
			LCD_SendCommand(0xC0);
		}
	}

	while(keyPadGetKey() != 0xFF);

	return (u8)temp_speed;
}