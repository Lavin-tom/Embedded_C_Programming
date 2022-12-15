//write an ECP for generating a delay of 100us @Fosc=12mzh
#include<reg51.h>
void delay_100us(void);
main()
{
	delay_100us();
	while(1);
}
void delay_100us(void)
{
	TMOD=0x03;			//Disabling timer 1 and selecting 
	TH0=156;				//T0 in M3 with s/w ctrl
	TR0=1;
	while(TF0==0);
	TR0=0;
	TF0=0;
}