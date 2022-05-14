/*wap ECP for add data at run time using switch*/

#include"header.h"
#define SW_PIN 0
main()
{
	u8 temp,counter=0;
	lcd_init();
	while(1)
	{
		temp='A'-1;
		lcd_cmd(0x01);		//command for clear the display
		counter=0;
		do
		{
			if(io_bit_read(PORT2,SW_PIN)==0)
			{
				temp++;
				counter++;
				while(io_bit_read(PORT2,SW_PIN)==0);
				if(counter==17)			//new line after reaching the last postion of first line
					lcd_cmd(0xc0);		//cmd for new line
				lcd_data(temp);
			}
		}while(temp<'Z');
		delay_ms(500); 	//to see z for 500 m
	}
}