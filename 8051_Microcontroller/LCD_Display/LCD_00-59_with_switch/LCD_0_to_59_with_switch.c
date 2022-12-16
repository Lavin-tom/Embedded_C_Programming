//LCD display 0 to 59 when press switch
#include "my_header.h"
#define pin_num 0
main()
{
		s8 temp=-1;
		lcd_init();
		lcd_cmd(0xc);											//cursor off
		while(1)
		{
			temp=-1;
			lcd_cmd(0x80);									//set cursor at home position
			do{
				if(io_bit_read(PORT2,pin_num)==0){				//when switch press
					temp++;																		
					while(io_bit_read(PORT2,pin_num)==0);		//wait until switch release
					lcd_cmd(0x80);													//set the cursor to home position
					lcd_data((temp/10)+48);									//extract first digit and convert to ascii
					lcd_data((temp%10)+48);									//extract second digit and convert to ascii
				}
			}while(temp<=58);														//loop increment until it reach 58
		}
}