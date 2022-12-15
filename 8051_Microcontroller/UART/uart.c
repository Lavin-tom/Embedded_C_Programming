//main_uart.c
#include <reg51.h>
main()
{
	//uart initialization
	SCON=0x50;
	TMOD|=0x20;
	TH1=253;	//for B9600
	TR1=1;		//start baudrate setting
	
	//send a 1 bytes of data
	SBUF='A';
	while(T1==0);		//waiting for data transfer
	T1=0;
	while(1);
}