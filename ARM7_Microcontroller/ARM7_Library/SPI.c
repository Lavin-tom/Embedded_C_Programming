//SPI.c
#include <lpc214x.h>
#include "SPI.h"

void SPI_Init()
{
	PINSEL0 = (PINSEL0 & (~(0x3f<<8))) | 0x15 << 8;
	SSEL0_DIR;
	SSEL0_SET;
	S0SPCR = 0x80;		//sck = PCLK divided by 8
	S0SPINT = 0;
	S0SPCR = 0x0020;	//ctrl register is 16 bits
}

unsigned char SPI_SendReceive(unsigned char Data)
{
	unsigned int Received_Data;
	S0SPDR = Data;
	while((S0SPSR & 0x80) == 0);
	Received_Data = S0SPDR;

	return Received_Data;
}
