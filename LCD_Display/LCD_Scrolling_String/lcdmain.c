/*wap ECP for scroll string on LCD Display*/

#include"header.h"
main()
{
	u8 i;
	lcd_init();
	for(i=0x80;i<=0x8f;i++)
	{
		if(i==0x8f)	//for circular looping 
			i=0x80;			//when reach the last postion,again start from first
		lcd_cmd(0xc);			//command for off the cursor
		lcd_cmd(i); 		//to set the cursor at home postion
		lcd_string("TESTING"); //passing string to the display
		delay_ms(250);		//delay of 1 sec
		lcd_cmd(0x01);		//command for clear the display
	}
	while(1);	//to avoid infinite loop
}