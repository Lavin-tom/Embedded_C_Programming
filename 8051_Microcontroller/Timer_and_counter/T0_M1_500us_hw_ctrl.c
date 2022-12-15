//write an ECP for timer/counter for 500u delay h/w control fosc=6mzh
#include<reg51.h>
mai()
{
	delay_500us();
	while(1);
}
void delay_500us(void)
{
	TMOD=0x09;			//T0 M1 with hardware ctrl
	TL0=65286&ff;		//lower 8 bit added to TL register
	TH0=65286>>8;		//higher 8 bit added to TH register
	TR0=1;					//timer 0 turn on 
	while(TF0==0);	//wait until overflow flag on
	TR0=0;					//timer 0 turn off
	TF0=0;
}