#include<reg51.h>
sbit s1 = P1^7;
sbit LED = P1^0;
main()
{
	while(1)
	{
		if(s1==0) //check for switch is in active low
			LED=1;  //active high LED
		else
			LED=0;
	}
}