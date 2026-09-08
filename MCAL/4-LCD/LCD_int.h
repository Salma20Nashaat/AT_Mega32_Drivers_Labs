#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_

#include "STD_TYPES.h"

void LCD_void_init(void);
void LCD_void_SendChar(u8 character);
void LCD_Send_Command(u8 command);
void LCD_Send_String(u8 *str);
void LCD_void_SendNumber(u32 num);
void LCD_void_GoToXY(u8 Row, u8 Col);

#endif