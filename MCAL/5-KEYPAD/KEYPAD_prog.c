#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "KEYPAD_int.h"
#include "KEYPAD_config.h"
#include "util/delay.h"

u8 KEYPAD_arr[4][4] = {
    {7,8,9,'/'},
    {4,5,6,'*'},
    {1,2,3,'-'},
    {'C',0,'=','+'}
};

void KEYPAD_voidInit(void)
{
    DIO_voidSetPinDirection(KEYPAD_ROWS_PORT, KEYPAD_ROW0_PIN, OUTPUT);
    DIO_voidSetPinDirection(KEYPAD_ROWS_PORT, KEYPAD_ROW1_PIN, OUTPUT);
    DIO_voidSetPinDirection(KEYPAD_ROWS_PORT, KEYPAD_ROW2_PIN, OUTPUT);
    DIO_voidSetPinDirection(KEYPAD_ROWS_PORT, KEYPAD_ROW3_PIN, OUTPUT);

    DIO_voidSetPinDirection(KEYPAD_COLS_PORT, KEYPAD_COL0_PIN, INPUT);
    DIO_voidSetPinDirection(KEYPAD_COLS_PORT, KEYPAD_COL1_PIN, INPUT);
    DIO_voidSetPinDirection(KEYPAD_COLS_PORT, KEYPAD_COL2_PIN, INPUT);
    DIO_voidSetPinDirection(KEYPAD_COLS_PORT, KEYPAD_COL3_PIN, INPUT);

    DIO_voidSetPinValue(KEYPAD_COLS_PORT, KEYPAD_COL0_PIN, HIGH);
    DIO_voidSetPinValue(KEYPAD_COLS_PORT, KEYPAD_COL1_PIN, HIGH);
    DIO_voidSetPinValue(KEYPAD_COLS_PORT, KEYPAD_COL2_PIN, HIGH);
    DIO_voidSetPinValue(KEYPAD_COLS_PORT, KEYPAD_COL3_PIN, HIGH);
	
}

u8 KEYPAD_u8GetPressedKey(void)
{
    u8 i, j;
    u8 rowPins[4] = {KEYPAD_ROW0_PIN, KEYPAD_ROW1_PIN, KEYPAD_ROW2_PIN, KEYPAD_ROW3_PIN};
    u8 colPins[4] = {KEYPAD_COL0_PIN, KEYPAD_COL1_PIN, KEYPAD_COL2_PIN, KEYPAD_COL3_PIN};

    for(i = 0; i< 4; i++)
    {
        
        DIO_voidSetPinValue(KEYPAD_ROWS_PORT, rowPins[0], HIGH);
        DIO_voidSetPinValue(KEYPAD_ROWS_PORT, rowPins[1], HIGH);
        DIO_voidSetPinValue(KEYPAD_ROWS_PORT, rowPins[2], HIGH);
        DIO_voidSetPinValue(KEYPAD_ROWS_PORT, rowPins[3], HIGH);
        DIO_voidSetPinValue(KEYPAD_ROWS_PORT, rowPins[i], LOW);

        for(j = 0; j < 4; j++)
        {
            if(DIO_u8ReadPinValue(KEYPAD_COLS_PORT, colPins[j]) == LOW)
            {
                _delay_ms(1000);
                while(DIO_u8ReadPinValue(KEYPAD_COLS_PORT, colPins[j]) == LOW); 
                return KEYPAD_arr[i][j];
            }
        }
    }
    return 255; 
}


