//write an ECP for measuring 500usec time interval using timer0 in m1 with Fosc=6mhz
//not completed

#include<reg51.h>
void delay_500us(void);
main()
{
	delay_500us();
	while(1);
}

void delay_500us(void)
{
	TMOD=0x01;						//timer 0 in M1 selected with s/w control
	TL0=65486&0xff;				//LSB 8 bit into TL register
	TH0=65486>>8;					//MSB 8 bit into TH register
	TR0=1;								//Timer 0 starts running 
	while(TF0==0);				//wait till overflow flag to set
	TR0=0;								//stop the timer
	TF0=0;
}