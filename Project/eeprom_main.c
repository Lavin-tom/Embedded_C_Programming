//eeprom.c
#include "header.h"
main()
{
	u8 temp;
	lcd_init();
	lcd_cmd(0xC); //cursor off
	i2c_byte_write_frame(0xA0,0x3,'h'); //write data into page 0

	temp=i2c_byte_read_frame(0xA0,0x3);
	lcd_data(temp);
	while(1);
}