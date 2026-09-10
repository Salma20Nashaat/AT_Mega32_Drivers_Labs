#ifndef KEYPADLCD_H_
#define KEYPADLCD_H_
#include "DIO_int.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

void keyPad_init();
u8 keyPadGetKey();

#define RS PIN2
#define RW PIN1
#define EN PIN0

//init
void LCD_init();
 
//char
void LCD_sendChar(u8 Data);
 
//send command
void LCD_SendCommand(u8 command);
 
//Send String
void LCD_SendString (u8 *str);

//Send Number
void LCD_SendNumber(u32 num);

u8 GetSpeed();

#endif