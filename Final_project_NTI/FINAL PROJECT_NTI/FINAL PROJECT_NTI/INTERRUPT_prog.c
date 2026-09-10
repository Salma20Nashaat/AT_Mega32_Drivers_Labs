#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"

#include "INTERRUPT_config.h"
#include "INTERRUPT_private.h"

void initExternalInterupts(void)

{	set_bit(MCUCR,MCUCR_ISC00);
	clr_bit(MCUCR,MCUCR_ISC01);
	
	set_bit(MCUCR,MCUCR_ISC10);
	clr_bit(MCUCR,MCUCR_ISC11);
	
	set_bit(GICR,GICR_INT0);
	set_bit(GICR,GICR_INT1);
}