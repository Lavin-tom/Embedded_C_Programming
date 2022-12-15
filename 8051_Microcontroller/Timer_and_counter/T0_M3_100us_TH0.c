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
	TMOD=0x33;			//Disabling timer 1 and selecting 
	TH0=156;				//T0 in M3 with s/w ctrl
	TR1=1;
	while(TF1==0);
	TR1=0;
	TF1=0;
}