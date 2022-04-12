//write a ECP for displaying 0-9 digits on the common anode segment
#include<reg51.h>
#include<delay.h>
#define SEG_CA P2
char code a[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
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