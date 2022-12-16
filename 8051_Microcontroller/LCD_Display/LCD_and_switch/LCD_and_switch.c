//LCD display and switch
#include "my_header.h"
#define pin_num 0
main()
{
		u8 temp='A'-1,count=0;
		lcd_init();
		lcd_cmd(0xc);				//cursor off
		while(1)
		{
			u8 temp='A'-1;
				do{
					if(io_bit_read(PORT2,pin_num)==0)
					{
						temp++;
						while(io_bit_read(PORT2,pin_num)==0);
						if(count==16)
							lcd_cmd(0xc0);
						if(count==32){
							lcd_cmd(0x2);
							count=0;
						}
						lcd_data(temp);
						count++;
					}
				}while(temp<'Z');
		}
}