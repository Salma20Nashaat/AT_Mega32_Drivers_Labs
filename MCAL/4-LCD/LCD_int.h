#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_

#include "STD_TYPES.h"

void LCD_void_init(void);
void LCD_void_SendChar(u8 character);
void LCD_SendCommand(u8 command);
void LCD_SendString(u8 *str);
void LCD_voidSendNumber(u8 num);

#endif