//delay.c
#include "my_header.h"
void delay_ms(u16 ms){
	u16 i;
	for(;ms>0;ms--){
		i=250;
		while(--i);
		i=247;
		while(--i);
	}
}