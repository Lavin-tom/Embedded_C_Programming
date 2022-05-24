//rtc.c
#include "header.h"
void rtc(u8 h,u8 m,u8 s)
{				
	//read rtc time and print it on a LCD
	lcd_cmd(0x1);
	lcd_string("CURRENT TIME");
	lcd_cmd(0xc0);
	h=i2c_byte_read_frame(0xD0,0x2); //read hours
	m=i2c_byte_read_frame(0xD0,0x1); //reading minutes
	s=i2c_byte_read_frame(0xD0,0x0); //reading seconds
	
	lcd_data(h/16+48);
	lcd_data(h%16+48);
	
	lcd_data(':');

	lcd_data(m/16+48);
	lcd_data(m%16+48);
	
	lcd_data(':');
	
	lcd_data(s/16+48);
	lcd_data(s%16+48);
	
	}