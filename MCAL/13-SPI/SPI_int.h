#ifndef SPI_INTERFACE_
#define SPI_INTERFACEH_

#include "STD_TYPES.h"

void SPI_MasterInit(void);
void SPI_SlaveInit(void);
void SPI_MasterTransmit(u8 data);
u8 SPI_SlaveReceive(void);

#endif