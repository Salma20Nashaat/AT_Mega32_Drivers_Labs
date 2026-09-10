#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC.h"
#include "DIO_int.h"
#include "DIO_private.h"
void ADC_Init (void)
{
   clr_bit(ADMUX_Reg, 7);// REFS1
    set_bit(ADMUX_Reg, 6); //REFS0
// freq/128
   set_bit(ADCSRA_Reg, 2); //ADPS2
    set_bit(ADCSRA_Reg, 1); //ADPS1
    set_bit(ADCSRA_Reg, 0); //ADPS0

    set_bit(ADCSRA_Reg, 7); //ADEN=1 ADC ENABLE-->ON
}

u16 ADC_Read (u8 channel)
{
	//change ADC channel (bit5)
	ADMUX_Reg = (ADMUX_Reg & 0xE0) | (channel & 0x1F);//SAVE FIRST 3BIT ,CHANGE LAST 5 BIT TO CHANNEL NUM 00000-->A0

    set_bit(ADCSRA_Reg, 6); 

    while (GET_BIT(ADCSRA_Reg, 4) == 0);//4-->ADIF

   set_bit(ADCSRA_Reg, 4); //CLR FLAG

    u16 adc_val = ADCL_Reg;// LOWER BIT ADCL
    adc_val |= (ADCH_Reg << 8);// ADCH FOR 10 BIT

    return adc_val;
}
