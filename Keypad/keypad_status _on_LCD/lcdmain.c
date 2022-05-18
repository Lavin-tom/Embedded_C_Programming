#include "header.h"
main()
{
	u8 temp;
	lcd_init();
	//lcd_string("Stay home");
	//lcd_cmd(0xc0);
	//lcd_string("Stay safe");
	while(1)
	{
	temp=keyscan();
	lcd_data(temp+48);
	}
}