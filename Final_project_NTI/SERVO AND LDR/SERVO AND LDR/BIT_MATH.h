#ifndef BIT_MATH_H
#define BIT_MATH_H

#define set_bit(VAR,BIT) ((VAR)|=(1<<(BIT)))
#define clr_bit(VAR,BIT) ((VAR)&=~(1<<(BIT)))
#define toggle_bit(VAR,BIT) ((VAR)^=(1<<(BIT)))
#define GET_BIT(VAR,BIT) (((VAR)>>(BIT))&1)

#endif