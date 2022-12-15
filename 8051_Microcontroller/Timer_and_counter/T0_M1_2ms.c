//write an ecp for delay of 2msec timer0 mode 1 with s/w ctrl fosc=6mzh
/*
solution
mode1=16
Tdelay=(2^16-x)*mct;
mct=12/6=2usec
2msec=(65536-x)*2usec
2000usec=(65536-x)*2usec
x=64536
*/
#include<reg51.h>
void delay_2ms(void);
main()
{
	delay_2ms();
	while(1);
}
void delay_2ms(void)
{
	TMOD=0x01;				//timer 0 mode 1 with s/w ctrl
	TL0=64536&ff;			//lower 8 bit to TL register
	TH0=64536>>8;					//higher 8 bit to TH register
	TR0=1;						//timer 0 turn on
	while(TF0==0);
	TR0=0;
	TF0=0;
}