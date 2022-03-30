#include<reg51.h>
#include<delay.h>
void main()
{
	int i,time=1000;
	for(i=0;i<=255;i++)
	{
		P1=i;
		ms_delay(time);
	}
}