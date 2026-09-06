#ifndef _INTERRUPT_PRIVATE_H
#define _INTERRUPT_PRIVATE_H

#include "STD_TYPES.h"

#define MCUCR   *((volatile u8 *)0x55)
#define GICR   *((volatile u8 *)0x5B)
#define GIFR   *((volatile u8 *)0x5A)
#define SREG    *((volatile u8 *)0x5F)

#endif