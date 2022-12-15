//write an ECP for measuring 1msec time interval using timer0 in m0 with Fosc=12mhz

#include<reg51.h>
void delay_1ms(void);
main()
{
	delay_1ms();
	while(1);
}
void delay_1ms(void)
{
	TMOD=0x00;				//timer 0 in M0 selected with s/w control
	TL0=7192&0x1f;		//LSB 5 bits into TL register
	TH0=7192>>5;			//MSB 8 bits into TH register
	TR0=1;						//timer 0 starts running
	while(TF0==0);		//waits for overflow flag to set
	TR0=0;						//stop the timer operation
	TF0=0;						
}