#include"lcd.h"	

main()
{
	//step1:LCD_Initialization
	Init_LCD();
	//store font into CGRAM
	store_font_CGRAM();
	//select position on the display
	write_cmd_LCD(0x88);//1st line last position
	//send to the display
	write_dat_LCD(0);
	while(1);
}