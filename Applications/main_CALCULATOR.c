#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include "KEYPAD_int.h"
#include "CALCULATOR_int.h"

int main(void)
{
    LCD_void_init();       
    KEYPAD_voidInit();  
  while(1)
  {	  
    Calculator_voidRun();  
  }
    return 0;
}