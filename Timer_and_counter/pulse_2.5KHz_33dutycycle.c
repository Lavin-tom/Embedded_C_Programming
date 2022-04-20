//write an ECP for generating the pulse with 33% duty cycle
//and 2.5KHz of train pulses. Fosc=12Mhz.

/*solution(paper work)
pulse frequency=2.5khz
pulse time(total time)=1/2.5khz=400usec
duty cycle=(Ton/Ttotal)*100%
33=(Ton/400)*100
Ton=132usec
Toff=Ttotal-Ton
Toff=400-132=268usec
*/

#include<reg51.h>
sbit pulse=P1^0;
void delay_132us(void);
void delay_268us(void);
main()
{
	while(1)
	{
		pulse=0;
		delay_268us();		//Toff=268usec
		pulse=1;	
		delay_132us();		//Ton=132usec
	}
}
void delay_268us(void)
{
	TMOD=0x03;			//T0 in M3 with s/w ctrl
	TL0=156;
	TR0=1;
	while(TF0==0);		//wait for overflow flag to set
	TR0=0;					
	TF0=0;
}
void delay_132us(void)
{
	TMOD=0x03;			//T0 in M3 with s/w ctrl
	TL0=156;
	TR0=1;
	while(TF0==0);		//wait for overflow flag to set
	TR0=0;					
	TF0=0;
}