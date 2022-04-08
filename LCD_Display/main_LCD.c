#include"lcd.h"
main()
{
//step1 - LCD Initialization
Init_LCD();

//step2 - Selecting the postion on the display
write_cmd_LCD(0x80);		//selecting starting postion on the 1st line

//sending ASCII value to display character
write_dat_LCD('A');
write_cmd_LCD(0x88);
write_str_LCD("INDIA");
	while(1);
}