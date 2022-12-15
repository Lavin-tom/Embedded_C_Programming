//write a ECP for displaying 0-9 digits on the common anode segment
#include<reg51.h>
#include"delay.h"
#define SEG_CA P2
char code a[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
void delay_ms(unsigned int Tdly_ms);
main()
{
	char i;
	while(1)
	{
		for(i=0;i<10;i++)
		{
			SEG_CA=a[i];
			delay_ms(1000);
		}
	}
}