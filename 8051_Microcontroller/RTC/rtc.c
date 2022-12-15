//rtc.c
#include "header.h"
#include<reg51.h>
sbit light=P3^3;
main()
{
	u8 h,m,s,n;
	lcd_init();
	//setting time to 11.59.50PM
	i2c_byte_write_frame(0xD0,0x2,0x23); //setting hour
	i2c_byte_write_frame(0xD0,0x1,0x59); //setting mins
	i2c_byte_write_frame(0xD0,0x0,0x50);	//setting seconds
	
	//read rtc time and print it on a LCD
	lcd_cmd(0xC); //cursor off
	while(1)
	{
	h=i2c_byte_read_frame(0xD0,0x2); //read hours
	m=i2c_byte_read_frame(0xD0,0x1); //reading minutes
	s=i2c_byte_read_frame(0xD0,0x0); //reading seconds
	
	
				
	lcd_cmd(0x80);
	lcd_data(h/16+48);
	//delay_ms(5000);
	lcd_data(h%16+48);
	//delay_ms(5000);	
	lcd_data(':');


	lcd_data(m/16+48);
	lcd_data(m%16+48);
	lcd_data(':');
	
	lcd_data(s/16+48);	
	lcd_data(s%16+48);
	//turn on led in each 5 seconds
	n=s%16;
	if(n>=1 && n<=5)
		light=1;
	else
		light=0;    
	}
}