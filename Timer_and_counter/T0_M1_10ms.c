//write an ECP for measuring 10ms time interval using timer0 in mode 1 with fosc 12mhz.

/*solution
mode 1-16
Tdelay=(2^16-x)*mct
mct=12/fosc
mct=12/12=1usec
10ms=(65536-x)*1usec
10000usec=(65536-x)*1usec
x=55536
*/

#include<reg51.h>
void delay_10ms(void);
main()
{
	delay_10ms();
	while(1);
}
void dealy_10ms(void)
{
	TMOD=0x01;				//timer 0 with s/w control mode 1 
	TL0=55536&0xff;			//LSB 8 bit to TL register
	TH0=55536>>8;			//MSB 8 bit to TH register
	TR0=1;						//timer 0 turn on
	while(TF0==0);		//wait for over flow flag on
	TR0=0;
	TF0=0;
}