/*Write an ECP for displaying binary equivalent of a
8-bit number on 8-LEDS(4 AH,4 AL)*/
#include"leds_8.h"
main()
{
	char ch=0xff;
	disp_bin_LEDs(ch);
	while(1);	
}