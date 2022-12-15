#include<reg51.h>
#include"delay.h"
void main()
{
	int time=1000;
	while(1)
	{
		P1=0;
		ms_delay(time);
		P1=0x18;
		ms_delay(time);
		P1=0x24;
		ms_delay(time);
		P1=0x42;
		ms_delay(time);
		P1=0x81;
		ms_delay(time);
	}
}