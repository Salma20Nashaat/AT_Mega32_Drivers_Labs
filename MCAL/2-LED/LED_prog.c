#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"

#include "LED_int.h"
#include "LED_config.h"
#include "LED_private.h"

void LED_voidInitialize(void)
{
    DIO_voidSetPinDirection(LED_PORT, LED_PIN, OUTPUT);
    DIO_voidSetPinValue(LED_PORT, LED_PIN, LOW);
}

void LED_voidOn(u8 LedId)
{
    DIO_voidSetPinValue(LED_PORT, LED_PIN, HIGH);
}

void LED_voidOff(u8 LedId)
{
    DIO_voidSetPinValue(LED_PORT, LED_PIN, LOW);
}

void LED_voidToggle(u8 LedId)
{
    u8 Local_u8CurrentState = DIO_u8ReadPinValue(LED_PORT, LED_PIN);
    if(Local_u8CurrentState == HIGH)
    {
        DIO_voidSetPinValue(LED_PORT, LED_PIN, LOW);
    }
    else
    {
        DIO_voidSetPinValue(LED_PORT, LED_PIN, HIGH);
    }
}