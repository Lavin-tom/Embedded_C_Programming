//write an ECP for counting external events applied on P3.4 and display it on LEDs

//counters of 8051 c0 and c1 are associated with p3.4 and p3.5 respectively
#include<reg51.h>
main()
{
	unsigned int cnt=0;				//count always positive
	TMOD=0x05;							//Counter 0 mode 1 with s/w ctrl
	TR0=1;									//counter start running
	while(1)
	{
		cnt=(TH0<<8)|TL0;			//TH and TL are two seperate integer
		P1=cnt;								//it can display lower 8 bit of 16 bit on LEDs
		//provide display function for view in LCD display
	}
}