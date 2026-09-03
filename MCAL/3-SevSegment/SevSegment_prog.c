#include "STD_TYPES.h"
#include "BIT_MATH.h"
 
#include "DIO_int.h"
 
#include "SevSegment_int.h"
#include "SevSegment_config.h"
#include "SevSegment_private.h"
 
void SevSegment_voidInitialize(void)
{
    DIO_voidSetPortDirection(SEVSEG_PORT, 0b11111111);
    DIO_voidSetPortValue(SEVSEG_PORT, 0b00000000);
}
 
void SevSegment_voidSetValue(u8 Num)
{
    u8 u8Pattern;
 
    if(Num > 9)
    {
        return; 
    }
 
    u8Pattern = SevSeg_arr[Num];
 
#if SEVSEG_COMMON_ANODE
    u8Pattern = ~u8Pattern;
#endif
 
    DIO_voidSetPortValue(SEVSEG_PORT, u8Pattern);
}