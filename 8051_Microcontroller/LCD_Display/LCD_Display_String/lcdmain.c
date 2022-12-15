#include"header.h"
main()
{
	lcd_init();
	lcd_string("Stay home");
	lcd_cmd(0xc0);
	lcd_string("Stay safe");
	while(1);
}