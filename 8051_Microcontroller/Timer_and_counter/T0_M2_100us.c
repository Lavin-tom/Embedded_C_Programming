//write an ecp for timer0 mode 2 with s/w ctrl
#include<reg51.h>
void delay_100us(void);
main()
{
	delay_100us();
	while(1);
}
void delay_100us(void)
{
	TMOD=0x02;
	TL0=156;
	TH0=156;
	TR0=1;
	while(TF0==0);
	TR0=0;
	TF0=0;
}