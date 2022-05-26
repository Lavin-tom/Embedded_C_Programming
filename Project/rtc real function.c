//rtc.c
#include "header.h"
void rtc(u8 h,u8 m,u8 s,u8 status)
{				
	//u8 y,mo,d;
	//read rtc time and print it on a LCD
	lcd_cmd(0x1);
	//lcd_string("CURRENT TIME");
	if(status==1)
		lcd_string("DEVICE ON");
	else
			lcd_string("DEVICE OFF");
	lcd_cmd(0xc0);
	h=i2c_read_frame(0xD0,0x2); //read hours
	m=i2c_read_frame(0xD0,0x1); //reading minutes
	s=i2c_read_frame(0xD0,0x0); //reading seconds
	//d=i2c_read_frame(0xD0,0x4); //reading day
	//mo=i2c_read_frame(0xD0,0x5);//reading months
	//y=i2c_read_frame(0xD0,0x6);//reading year
	
	lcd_data(h/16+48);
	lcd_data(h%16+48);
	
	lcd_data(':');

	lcd_data(m/16+48);
	lcd_data(m%16+48);
	
	lcd_data(':');
	
	lcd_data(s/16+48);
	lcd_data(s%16+48);
	
	
	/*
	lcd_data(':');
	lcd_data(d/16+48);
	lcd_data(d%16+48);
	
	lcd_data(':');
	lcd_data(mo/16+48);
	lcd_data(mo%16+48);
	
	lcd_data(':');
	lcd_data(y/16+48);
	lcd_data(y%16+48);
	*/
	
	}