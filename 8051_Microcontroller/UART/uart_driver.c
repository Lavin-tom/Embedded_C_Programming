//uart driver
#include <reg51.h>
#include "header.h"

//uart initilization
void uart_init(u16 baud)
{
	SCON=0x50;
	TMOD|=0x20;
	switch(baud)
	{
		case 7200: TH1=252; break;
		case 9600: TH1=253; break;
		case 14400: TH1=254; break;
		case 28800: TH1=255; break;
		case 57600: TH1=255; PCON=(1<<8); break;
		default: TH1=253;
	}
	TR1=1;
}

void uart_tx(u8 d)
{
	SBUF=d;
	while(T1==0);
	T1=0;
}