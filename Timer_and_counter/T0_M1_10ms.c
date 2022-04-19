//write an ECP for measuring 10ms time interval using timer0 in mode 1 with fosc 12mhz.

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