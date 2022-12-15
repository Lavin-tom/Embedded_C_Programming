//delay_ms
#include "header.h"
extern void delay_ms(u16 ms)
{
	unsigned int i;
	for(ms;ms>0;ms--)
	{
		for(i=122;i>0;i--);
	}
}