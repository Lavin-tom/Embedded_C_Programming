//main_uart.c
#include "header.h"
main()
{
	u8 i;
	uart_init(9600);
	while(1)
	{
		for(i=0;i<26;i++)
		{
		uart_tx('A'+i);
		}
	}
} 