//write an ecp for delay of 2msec timer0 mode 0 with s/w ctrl fosc=6mzh
/*
solution
mode0=13
Tdelay=(2^13-x)*mct;
mct=12/6=2usec
2msec=(8192-x)*2usec
2000usec=(8192-x)*2usec
x=7192
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
	TMOD=0x00;				//timer 0 mode 0 with s/w ctrl
	TL0=7192&1f;			//lower 5 bit to TL register
	TH0=7192>>5;					//higher 8 bit to TH register
	TR0=1;						//timer 0 turn on
	while(TF0==0);
	TR0=0;
	TF0=0;
}