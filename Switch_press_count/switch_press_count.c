#include<reg51.h>
sbit Switch1 = P2^0;
void ms_delay();
void disp_bin_LEDs (char);
void main()
{
	char count=0;
	while(1)
	{
	if(Switch1==0)
	{
		ms_delay();
		count++;
		while(Switch1==0)
	disp_bin_LEDs(count);
	}
	}
	
}
void ms_delay()
{
	int i,j;
	for(i=0;i<500;i++)
		for(j=0;j<113;j++);
}

void disp_bin_LEDs(char i)
{
	P1=i; 
}	