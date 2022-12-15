/*wap ECP for flash LCD message for 5 times at the rate of 1 sec
after clear the lcd screen and stop flashing*/

#include"header.h"
main()
{
	u8 i;
	lcd_init();
	for(i=0;i<5;i++)
	{
		lcd_cmd(0xc);			//command for off the cursor
		lcd_cmd(0x80); 		//to set the cursor at home postion
		lcd_string("TESTING"); //passing string to the display
		delay_ms(1000);		//delay of 1 sec
		lcd_cmd(0x01);		//command for clear the display
		delay_ms(1000);
	}
	while(1);	//to avoid infinite loop
}