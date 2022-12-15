//write an ecp for delay of 1sec timer1 mode 1 with s/w ctrl fosc=12mzh
//not yet completed
/*
solution
mode1=16
Tdelay=(2^16-x)*mct;
mct=12/12=1usec
1sec=(65536-x)*1usec
1000000usec=(65536-x)*1usec
x=934464
*/

#include<reg51.h>
void delay_1s(void);
main()
{
	delay_1s();
	while(1);
}
void delay_1s(void)
{
	TMOD=0x10;				//timer 1 mode 1 with s/w ctrl
	TL0=934464&ff;			//lower 8 bit to TL register
	TH0=934464>>8;					//higher 8 bit to TH register
	TR1=1;						//timer 0 turn on
	while(TF1==0);
	TR1=0;
	TF1=0;
}