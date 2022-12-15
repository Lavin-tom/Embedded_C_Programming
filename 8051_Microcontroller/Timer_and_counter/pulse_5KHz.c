//write an ECP for generating the pulse with 50% duty cycle
//and 5KHz of train pulses. Fosc=12Mhz.

/*solution(paper work)
pulse frequency=5khz
pulse time(total time)=1/5khz=200usec
duty cycle=(Ton/Ttotal)*100%
50=(Ton/200)*100
Ton=100usec
Toff=Ttotal-Ton
Toff=200-100=100usec
*/

#include<reg51.h>
sbit pulse=P1^0;
void delay_100us(void);
main()
{
	while(1)
	{
		pulse=0;
		delay_100us();		//Toff=100usec
		pulse=1;	
		delay_100us();		//Ton=100usec
	}
}
void delay_100us(void)
{
	TMOD=0x03;			//T0 in M3 with s/w ctrl
	TL0=156;
	TR0=1;
	while(TF0==0);		//wait for overflow flag to set
	TR0=0;					
	TF0=0;
}