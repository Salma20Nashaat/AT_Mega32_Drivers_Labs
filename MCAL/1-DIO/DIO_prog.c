#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_voidIntinitialization(void)
{
    DDRA = DIO_PORTA_DIRECTION;
    DDRB = DIO_PORTB_DIRECTION;
    DDRC = DIO_PORTC_DIRECTION;
    DDRD = DIO_PORTD_DIRECTION;
}

void DIO_voidSetPinDirection(u8 PortID, u8 PinID, u8 Direction)
{
    if(PortID < 4 && PinID < 8)
    {
        if(Direction == OUTPUT)
        {
            switch(PortID)
            {
                case PORTA: set_bit(DDRA, PinID); break;
                case PORTB: set_bit(DDRB, PinID); break;
                case PORTC: set_bit(DDRC, PinID); break;
                case PORTD: set_bit(DDRD, PinID); break;
            }
        }
        else if(Direction == INPUT)
        {
            switch(PortID)
            {
                case PORTA: clr_bit(DDRA, PinID); break;
                case PORTB: clr_bit(DDRB, PinID); break;
                case PORTC: clr_bit(DDRC, PinID); break;
                case PORTD: clr_bit(DDRD, PinID); break;
            }
        }
        else
        {
            
        }
    }
    else
    {

    }
}

void DIO_voidSetPinValue(u8 PortID, u8 PinID, u8 Value)
{
    if(PortID < 4 && PinID < 8)
    {
        if(Value == HIGH)
        {
            switch(PortID)
            {
                case PORTA: set_bit(DPORTA, PinID); break;
                case PORTB: set_bit(DPORTB, PinID); break;
                case PORTC: set_bit(DPORTC, PinID); break;
                case PORTD: set_bit(DPORTD, PinID); break;
            }
        }
        else if(Value == LOW)
        {
            switch(PortID)
            {
                case PORTA: clr_bit(DPORTA, PinID); break;
                case PORTB: clr_bit(DPORTB, PinID); break;
                case PORTC: clr_bit(DPORTC, PinID); break;
                case PORTD: clr_bit(DPORTD, PinID); break;
            }
        }
        else
        {
            
        }
    }
    else
    {

    }
}

u8 DIO_u8ReadPinValue(u8 PortID, u8 PinID)
{
    u8 U8_Result = 0;
    if(PortID < 4 && PinID < 8)
    {
        switch(PortID)
        {
            case PORTA: U8_Result = get_bit(PINA, PinID); break;
            case PORTB: U8_Result = get_bit(PINB, PinID); break;
            case PORTC: U8_Result = get_bit(PINC, PinID); break;
            case PORTD: U8_Result = get_bit(PIND, PinID); break;
        }
    }
    else
    {

    }
    return U8_Result;
}

void DIO_voidSetPortDirection(u8 PortID, u8 Direction)
{
    if(PortID < 4)
    {
        switch(PortID)
        {
            case PORTA: DDRA = Direction; break;
            case PORTB: DDRB = Direction; break;
            case PORTC: DDRC = Direction; break;
            case PORTD: DDRD = Direction; break;
        }
    }
}

void DIO_voidSetPortValue(u8 PortID, u8 Value)
{
    if(PortID < 4)
    {
        switch(PortID)
        {
            case PORTA:DPORTA = Value; break;
            case PORTB:DPORTB = Value; break;
            case PORTC:DPORTC = Value; break;
            case PORTD:DPORTD = Value; break;
        }
    }
}

u8 DIO_u8ReadPortValue(u8 PortID)
{
    u8 U8_Result = 0;
    if(PortID < 4)
    {
        switch(PortID)
        {
            case PORTA: U8_Result = PINA; break;
            case PORTB: U8_Result = PINB; break;
            case PORTC: U8_Result = PINC; break;
            case PORTD: U8_Result = PIND; break;
        }
    }
    return U8_Result;
}