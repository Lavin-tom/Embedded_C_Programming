//rtc.c
#include "header.h"
void rtc(u8 h,u8 m)
{				
	//read rtc time and print it on a LCD
	lcd_cmd(0xC); //cursor off
	lcd_cmd(0x1);
	h=i2c_byte_read_frame(0xD0,0x2); //read hours
	m=i2c_byte_read_frame(0xD0,0x1); //reading minutes
	//s=i2c_byte_read_frame(0xD0,0x0); //reading seconds
	
	lcd_data(h/16+48);
	lcd_data(h%16+48);
	
	lcd_data(':');


	lcd_data(m/16+48);
	lcd_data(m%16+48);
	
	}