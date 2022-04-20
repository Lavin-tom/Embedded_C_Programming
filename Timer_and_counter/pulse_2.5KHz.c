//write an ECP for generating the pulse with 25% duty cycle
//and 2.5KHz of train pulses. Fosc=12Mhz.

/*solution(paper work)
pulse frequency=2.5khz
pulse time(total time)=1/2.5khz=400usec
duty cycle=(Ton/Ttotal)*100%
25=(Ton/400)*100
Ton=100usec
Toff=Ttotal-Ton
Toff=400-100=300usec
*/

#include<reg51.h>
sbit pulse=P1^0;
void delay_100us(void);
main()
{
	while(1)
	{
		pulse=0;
		delay_100us();		//calling same function for 3 times
		delay_100us();		//to get 300usec delay
		delay_100us();		//Toff=300usec
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