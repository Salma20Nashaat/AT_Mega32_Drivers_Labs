#include "UART_int.h"
#include "UART_config.h"
#include "UART_private.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "avr/interrupt.h"

volatile u8 UART_data_Transmit ;
volatile u8 UART_RX_flag = 0;
volatile u8 UART_data_Receiv ;
volatile u8 UART_TX_flag = 0;

void void_UartInit(void)
{   //UCSRA U2X=1 because of the error of the Baut rate,ASYNC
	set_bit(UCSRA,UCSRA_U2X);
	clr_bit(UCSRA,UCSRA_MPCM);
	
	//UCSRB
	
	
	//Opent  TX
	/*set_bit(UCSRB,UCSRB_UDRIE);*/
	set_bit(UCSRB,UCSRB_RXCIE);
	/*set_bit(UCSRB,UCSRB_TXCIE);*/
	set_bit(UCSRB,UCSRB_RXEN);
	/*set_bit(UCSRB,UCSRB_TXEN);*/
	
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
	
	UBRRH =(u8)(UBRR_value>>8); //UCSRC_URSEL =0 THIS MAKES ME WRITE ON THE UBRRH
}
u8 UART_ReceivData(void)
{
	u8 local_RX = 0;
	if(UART_RX_flag == 1)
	{
		local_RX = UART_data_Receiv;
		UART_RX_flag =0;
	}
	return local_RX;
}
// void UART_TransmitData(u8 data)
// {
// 	UART_data_Transmit = data;
// 	UART_TX_flag =1;
// 	set_bit(UCSRB,UCSRB_UDRIE);
// }

ISR(USART_RXC_vect)
{
	UART_data_Receiv =UDR;
	UART_RX_flag =1;
}

// ISR(USART_UDRE_vect)
// {
// 	if(UART_TX_flag == 1)
// 	{
// 		UDR = UART_data_Transmit;
// 		UART_TX_flag =0;
// 		clr_bit(UCSRB,UCSRB_UDRIE);
// 	}
//}