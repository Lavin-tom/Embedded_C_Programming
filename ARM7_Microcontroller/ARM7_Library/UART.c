//uart.c

#include <lpc214x.h>
#include "UART.h"

void UART_Init()
{
	//configure the pins as uart pins				
	PINSEL0 = (PINSEL0 & 0xfffffff0) | (0x00000005);
	//put the braud value in DLL and DLM  and FDR
	U0LCR = 0x80;
	U0DLL = 0x41;									
	U0DLM = 0x00;
	U0FDR = 0x42;
	//U0LCR = 0x00;

	//load LCR - Line ctrol register
	U0LCR = 0x03;
}
//Transmit data
void UART_Transmit_Byte(unsigned char Data)
{
	while((U0LSR & 0x40)==0);		//check for bit 6 status wait until its not empty
	U0THR = Data;
}

//to receive data
unsigned char UART_Receive(void)
{
	unsigned char Data;
	while((U0LSR & 0x01)== 0);
	Data = U0RBR;
	return Data;
}
//to transmitting string
void UART_Transmit_String(unsigned char *string)
{
	while(*string != 0)
	{
		UART_Transmit_Byte(*string);
		string++;
	}
}
