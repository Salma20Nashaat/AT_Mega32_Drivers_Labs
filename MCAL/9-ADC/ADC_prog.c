#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "ADC_H.h"

void ADC_Init (void)
{   set_bit(ADMUX_Reg,6);
	clr_bit(ADMUX_Reg,7);
	
	set_bit(ADCSRA_Reg,ADCSRA_ADEN);
	
	set_bit(ADCSRA_Reg,ADCSRA_ADPS0);
	set_bit(ADCSRA_Reg,ADCSRA_ADPS1);
	clr_bit(ADCSRA_Reg,ADCSRA_ADPS2);
}
u16 ADC_Read(u8 ch) {
	
	clr_bit(ADMUX_Reg, 0);
	clr_bit(ADMUX_Reg, 1);
	clr_bit(ADMUX_Reg, 2);
	clr_bit(ADMUX_Reg, 3);
	clr_bit(ADMUX_Reg, 4);

	if (get_bit(ch, 0) == 1) set_bit(ADMUX_Reg, 0);
	if (get_bit(ch, 1) == 1) set_bit(ADMUX_Reg, 1);
	if (get_bit(ch, 2) == 1) set_bit(ADMUX_Reg, 2);

	
	set_bit(ADCSRA_Reg, 6);
	while (get_bit(ADCSRA_Reg, 6) == 1);

	u16 adc_value = ADCL_Reg;
	adc_value += (ADCH_Reg * 256);

	return adc_value;
}





