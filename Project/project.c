//lcd main.c//
#include "header.h"
#include<reg51.h>
sbit light=P2^4;
sbit pass_light=P2^2;
main()
{
	pass_light=0;
	char i,j=0,k=0,n;
	u8 h,m,temp=0,pass,pass_[4];
	u8 count=0,flag=0;
	u8 hh,HH,mm,MM,hh_eeprom,mm_eeprom,MM_eeprom,HH_eeprom;
	u8 hh_off_eeprom,mm_off_eeprom,MM_off_eeprom,HH_off_eeprom;
	//eeprom
	lcd_init();
	
	//RTC function for real time clock	
	//setting on rtc to 12.25.00AM
	i2c_byte_write_frame(0xD0,0x2,0x00); //setting hour
	i2c_byte_write_frame(0xD0,0x1,0x10); //setting mins			
	//i2c_byte_write_frame(0xD0,0x3,0x15); //setting secs
	
	lcd_cmd(0xC);	//cursor off
	lcd_cmd(0x1);
	lcd_string("WELCOME");
	delay_ms(700);
	lcd_cmd(0x1);
	lcd_string("LOGIN TO");
	delay_ms(500);
	lcd_cmd(0xc0);
	lcd_string("UPDATE");
	delay_ms(500);
	lcd_cmd(0x1);
	lcd_string("ON AND OFF TIME");
	delay_ms(500);
	lcd_cmd(0xc0);
	lcd_string("PRESS / TO LOGIN");

	temp=keyscan();
	switch(temp)
	{
		case 8: 
			//login 
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
			
			for(m=0;m<4;m++)
			{
			pass=keyscan();
			if(pass!=8 || pass!=10 || pass!=48)
			{
				pass_[m]=pass;
				lcd_data(42);
				delay_ms(500);
			}
			}
			lcd_cmd(0x1);
				
			i2c_byte_write_frame_eeprom(0xa0,0x0,'1');
			delay_ms(500);
			i2c_byte_write_frame_eeprom(0xa0,0x1,'2');
			delay_ms(500);
			i2c_byte_write_frame_eeprom(0xa0,0x2,'3');
			delay_ms(500);
			i2c_byte_write_frame_eeprom(0xa0,0x3,'4');
			delay_ms(500);
			
			for(i=0x0;i<=0x3;i++)
			{
				temp=i2c_byte_read_frame_eeprom(0xa0,i);
				//lcd_data(temp);
				delay_ms(500);
				if(temp==pass_[j])
				{
				count++;
				}
				j++;
			}
			//lcd_cmd(0x1);
			//lcd_string("VALIDATING..");
			if(count==4){
				flag=1;
				lcd_cmd(0x1);
				lcd_string("SUCCESS");
				pass_light=1;
			}
			else{
				flag=0;
				lcd_string("FAILED");
				delay_ms(300);
				pass_light=0;
			}
			break;
			
		case 10:
		//set on_time to eeprom
			lcd_cmd(0x1);
			lcd_string("ADD ON_TIME");
			delay_ms(500);
			lcd_cmd(0x1);
			lcd_string("HH:MM");
			delay_ms(500);
			lcd_cmd(0xc0);
			for(i=0x4;i<=0x7;i++)
			{
				if(i==0x06)
					lcd_string(":");
				n=keyscan();
				lcd_data(n);
				delay_ms(500);
				i2c_byte_write_frame_eeprom(0xa0,i,n);
				delay_ms(500);
			}
			lcd_cmd(0x1);
			lcd_string("ON_TIME");
			lcd_cmd(0xc0);
			lcd_string("UPDATED");
		break;
		
		case 48:
		//set off_time to eeprom
			lcd_cmd(0x1);
			lcd_string("ADD OFF_TIME");
			delay_ms(500);
			lcd_cmd(0x1);
			lcd_string("HH:MM");
			delay_ms(500);
			lcd_cmd(0xc0);
			for(i=0x8;i<=0xB;i++)
			{
				if(i==0xA)
					lcd_string(":");
				n=keyscan();
				lcd_data(n);
				delay_ms(500);
				i2c_byte_write_frame_eeprom(0xa0,i,n);
				delay_ms(500);
			}
			lcd_cmd(0x1);
			lcd_string("OFF_TIME");
			lcd_cmd(0xc0);
			lcd_string("UPDATED");
			break;
			
			case 4:
			lcd_cmd(0x1);
			lcd_string("CURRENT TIME");
			rtc(h,m);
		}
	
	while(1)
	{
		//eeprom HH:hh : MM:mm
		h=i2c_byte_read_frame(0xD0,0x2);
		
		m=i2c_byte_read_frame(0xD0,0x1);
		
		HH=(h/16+48);
		
		hh=(h%16+48);
		
		MM=(m/16+48);
		
		mm=(m%16+48);
		
		//read on time from eeprom
		hh_eeprom=i2c_byte_read_frame_eeprom(0xa0,0x5);
		delay_ms(100);
		//lcd_data(hh_eeprom);
		HH_eeprom=i2c_byte_read_frame_eeprom(0xa0,0x4);
		delay_ms(100);
		//lcd_data(HH_eeprom);
		mm_eeprom=i2c_byte_read_frame_eeprom(0xa0,0x7);
		delay_ms(100);
		//lcd_data(mm_eeprom);
		MM_eeprom=i2c_byte_read_frame_eeprom(0xa0,0x6);
		delay_ms(100);

		//read off time from eeprom
		hh_off_eeprom=i2c_byte_read_frame_eeprom(0xa0,0x9);
		delay_ms(100);
		//lcd_data(hh_eeprom);
		HH_off_eeprom=i2c_byte_read_frame_eeprom(0xa0,0x8);
		delay_ms(100);
		//lcd_data(HH_eeprom);
		mm_off_eeprom=i2c_byte_read_frame_eeprom(0xa0,0xB);
		delay_ms(100);
		//lcd_data(mm_eeprom);
		MM_off_eeprom=i2c_byte_read_frame_eeprom(0xa0,0xA);
		delay_ms(100);
		
		//if(hh >= hh_eeprom && HH >=HH_eeprom && mm >= mm_eeprom && MM >=MM_eeprom)
		//if((HH_eeprom < HH < HH_off_eeprom)&& (hh_eeprom < hh < hh_off_eeprom)&& (MM_eeprom < MM < MM_off_eeprom)&& (mm_eeprom < mm < mm_off_eeprom))
		if(mm < mm_off_eeprom)  //mm_off_eeprom)
				light=1;
		else
				light=0;	
	}
	}
