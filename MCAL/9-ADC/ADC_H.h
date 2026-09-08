#ifndef ADC_H_
#define ADC_H_

#include "STD_TYPES.h"

#define ADMUX_Reg 	*((volatile u8*)0x27) 	// ADC Multiplexer Register
#define ADCSRA_Reg 	*((volatile u8*)0x26) 	// ADC Control And Status Register
#define ADCH_Reg 	*((volatile u8*)0x25) 		// ADC High Register
#define ADCL_Reg 	*((volatile u8*)0x24) 		// ADC Low Register

#define ADCSRA_ADPS0  0
#define ADCSRA_ADPS1  1
#define ADCSRA_ADPS2  2
#define ADCSRA_ADSC   6
#define ADCSRA_ADEN   7

extern void ADC_Init (void); // ADC Initialization And Enable
extern u16 ADC_Read (u8); // Read From The ADC Channel


#endif /* ADC_INITIALIZATION_H_ */