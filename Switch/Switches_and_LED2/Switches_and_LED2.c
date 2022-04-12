#include<reg51.h>
sbit s1 = P1^0;
sbit s2 = P1^1;
sbit LED = P1^7;
main()
{
	while(1)
	{
		if(s1==0 || s2==0) //check for switch is in active low
			LED=1;  //active high LED
		else
			LED=0;
	}
}