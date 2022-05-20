//lcd main.c//

#include "header.h"
main()
{
	u8 i,j=0;
	u8 h,m,s,temp,pass,pass_[4]={49,50,51,52},default_pass;
	u8 temp1,temp2,count=0;
	//eeprom
	lcd_init();
	
	//RTC function for real time clock	
	//setting time to 11.59.50PM
	i2c_byte_write_frame(0xD0,0x2,0x23); //setting hour
	i2c_byte_write_frame(0xD0,0x1,0x59); //setting mins			
	
	lcd_cmd(0xC);	//cursor off
	while(1)
	{
	temp=keyscan();
		if(temp==13)
		{
			lcd_cmd(0x1);
			lcd_string("CURRENT TIME");
			lcd_cmd(0xc0);
			rtc(h,m);
		}
		else if(temp==8)
		{
			lcd_cmd(0x1);
			lcd_string("LOGIN");
			delay_ms(500);
			lcd_cmd(0x1); //clear the display
			lcd_string("ENTER");
			delay_ms(500);
			lcd_cmd(0x1);
			lcd_string("PASSWORD");
			delay_ms(500);
			lcd_cmd(0xC0);
			delay_ms(500);
			//lcd_string("****");
			//pass=keyscan();
			//lcd_data(pass);
			delay_ms(500);
			lcd_cmd(0x1);
				
			i2c_byte_write_frame_eeprom(0xa0,0x0,'1');
			delay_ms(500);
			i2c_byte_write_frame_eeprom(0xa0,0x1,'2');
			delay_ms(500);
			i2c_byte_write_frame_eeprom(0xa0,0x2,'3');
			delay_ms(500);
			i2c_byte_write_frame_eeprom(0xa0,0x3,'4');
			delay_ms(500);
			
			//reading from eeprom
			/*
			temp=i2c_byte_read_frame_eeprom(0xa0,0x0);
			lcd_data(temp);
			delay_ms(500);
			temp=i2c_byte_read_frame_eeprom(0xa0,0x1);
			lcd_data(temp);
			delay_ms(500);
			temp=i2c_byte_read_frame_eeprom(0xa0,0x2);
			lcd_data(temp);
			delay_ms(500);
			temp=i2c_byte_read_frame_eeprom(0xa0,0x3);
			lcd_data(temp);
			delay_ms(500);
			*/
			
			
			for(i=0x0;i<=0x3;i++)
			{
				temp=i2c_byte_read_frame_eeprom(0xa0,i);
				lcd_data(temp);
				delay_ms(500);
				if(temp==pass_[j])
				{
				count++;
				}
				j++;
			}
			lcd_cmd(0x1);
			if(count==4)
				lcd_string("SUCESS");
			else
				lcd_string("FAILED");
		}
	}
	}
