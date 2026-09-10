#include "UART_int.h"
#include "UART_config.h"
#include "UART_private.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "avr/interrupt.h"

volatile u8 UART_data ;
volatile u8 UART_flag = 0;

void void_UartInit(void)
{   //UCSRA U2X=1 because of the error of the Baut rate,ASYNC
	set_bit(UCSRA,UCSRA_U2X);
	clr_bit(UCSRA,UCSRA_MPCM);
	
	//UCSRB
	//set_bit(UCSRB_UDRIE);
	/*set_bit(UCSRB,UCSRB_TXCIE);*/
	//Opent RX
	set_bit(UCSRB,UCSRB_RXCIE);
	set_bit(UCSRB,UCSRB_RXEN);
	set_bit(UCSRB,UCSRB_TXEN);
	
	//UCSRC REG NOT UBRRH
	//USMSEL= 0  ASYNC
	//UPM1 =0 UPM0 = 0  DISAPLED PRIATY
	//STOP 1BIT =0
	//CHARACTER SIZE 8bit, SET UCSZ0,UCSZ1, CLR UCSZ2
	clr_bit(UCSRB,UCSRB_UCSZ2);
	UCSRC = 0b10000110;
	
	//UBRRH  BAUT rate 9600  F=1MH
	u16 UBRR_value = 12;
	UBRRL =(u8)(UBRR_value);  //12
	
	UBRRH =(u8)(UBRR_value>>8); //UCSRC_URSEL =0
}
u8 UART_ReceivData(void)
{
	u8 UART_local = 0;
	while (UART_flag == 0);
	UART_local = UART_data;
	UART_flag =0;
	return UART_local;
}
ISR(USART_RXC_vect)
{
	UART_data = UDR;
	UART_flag = 1;
}