#include<reg51.h>
#define LEDS P1
#define BYTE_LEV 1

#if BYTE_LEV
void disp_bin_LEDs(char ch)
{
	LEDS=ch^0x0f;          
}
#else
sbit led1=P1^0;
sbit led2=P1^1;
sbit led3=P1^2;
sbit led4=P1^3;
sbit led5=P1^4;
sbit led6=P1^5;
sbit led7=P1^6;
sbit led8=P1^7;

void disp_bin_LEDs(char ch)
{
	led1=((ch>>0)&1)?0:1;
	led2=((ch>>1)&1)?0:1;
	led3=((ch>>2)&1)?0:1;
	led4=((ch>>3)&1)?0:1;
	led5=((ch>>4)&1)?1:0;
	led6=((ch>>5)&1)?1:0;
	led7=((ch>>6)&1)?1:0;
	led8=((ch>>7)&1)?1:0;			
}
#endif
