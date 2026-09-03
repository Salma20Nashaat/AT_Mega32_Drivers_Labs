#ifndef _LED_INTERFACE_H_
#define _LED_INTERFACE_H_

#define LED    0

void LED_voidInitialize(void);
void LED_voidOn(u8 LedId);
void LED_voidOff(u8 LedId);
void LED_voidToggle(u8 LedId);

#endif
