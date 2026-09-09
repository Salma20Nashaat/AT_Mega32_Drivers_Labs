#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_int.h"
#include "DIO_private.h"

void SPI_MasterInit(void)
{
	set_bit(DDRB, 4);
	set_bit(DDRB, 5);
	set_bit(DDRB, 7);
	
	clr_bit(DDRB, 6);

	set_bit(SPCR, SPCR_SPE);
	set_bit(SPCR, SPCR_MSTR);
	set_bit(SPCR, SPCR_SPR0);
}

void SPI_SlaveInit(void)
{
	set_bit(DDRB, 6);
	
	clr_bit(DDRB, 5);
	clr_bit(DDRB, 7);
	clr_bit(DDRB, 4);

	set_bit(SPCR, SPCR_SPE);
}

void SPI_MasterTransmit(u8 data)
{
	clr_bit(DPORTB, 4);

	SPDR = data;

	while (get_bit(SPSR, SPSR_SPIF) == 0);

	set_bit(DPORTB, 4);
}

u8 SPI_SlaveReceive(void)
{
	while (get_bit(SPSR, SPSR_SPIF) == 0);

	return SPDR;
}