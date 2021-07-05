
#include "ATMEGA32_REGISTERS.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART.h"


void UART_Init(void)
{
	
	//Enable RX And Tx
	SET_BIT(UCSRB,3);
	SET_BIT(UCSRB,4);
	
	//Setting the Frame formate: 8bits, no parity, one stop bits.
	UCSRC = 0b10000110;
	
	//Setting the baud rate to 9600
	UBRRH=0;
	UBRRL=103;
	
}

void UART_Send(U8 Data)
{
	while(GET_BIT(UCSRA, 5)==0);
	UDR=Data;
}

U8   UART_Recieve(void)
{
	while(GET_BIT(UCSRA, 7)==0);
	return UDR;
}
