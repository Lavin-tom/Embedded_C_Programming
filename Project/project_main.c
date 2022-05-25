//main.c//

#include "header.h"
#include<reg51.h>
sbit light=P2^4;
sbit pass_light=P2^2;
main()
{
	u8 i,j=0,k=0,n;
	u8 h,m,s,temp=0,pass,pass_[4];
	u8 count=0,flag=0;
	u8 hh,HH,mm,MM,hh_eeprom,mm_eeprom,MM_eeprom,HH_eeprom;
	u8 hh_off_eeprom,mm_off_eeprom,MM_off_eeprom,HH_off_eeprom;
	//time device initially turned off
	light=0;
	//light when turn on when login with correct password,initially set as off
	pass_light=0;
	lcd_init();		//lcd initialization
	//RTC function for real time clock	
	//setting on rtc to 00.10.00
	i2c_byte_write_frame(0xD0,0x2,0x00); //setting hour
	i2c_byte_write_frame(0xD0,0x1,0x10); //setting mins			
	i2c_byte_write_frame(0xD0,0x0,0x55); //setting secs
				
	//eeprom	
	//default password saved to the eeprom
	//default password set as 1234
	i2c_byte_write_frame(0xa0,0x0,'1');
	delay_ms(100);
	i2c_byte_write_frame(0xa0,0x1,'2');
	delay_ms(100);
	i2c_byte_write_frame(0xa0,0x2,'3');
	delay_ms(100);
	i2c_byte_write_frame(0xa0,0x3,'4');
	delay_ms(100);
	
	//welcome notes repeat every time turn on the device
	lcd_cmd(0xC);	//cursor off
	lcd_cmd(0x1);	//clear the lcd Display
	lcd_string("WELCOME");
	delay_ms(500);
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
	
	//get input through keypad
	temp=keyscan();
	//while repeat until press ce button
	while(temp!=42)
	{
	switch(temp)
	{
		case 8: 
			//login function
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

			for(i=0x0;i<=0x3;i++)
			{
				temp=i2c_byte_read_frame(0xa0,i);
				delay_ms(300);
				if(temp==pass_[j])
				{
				count++;
				}
				j++;
			}
			if(count==4){
				flag=1;
				lcd_cmd(0x1);
				lcd_string("SUCCESS");
				pass_light=1;
			}
			else{
				flag=0;
				lcd_cmd(0x1);
				lcd_string("FAILED");
				delay_ms(300);
				pass_light=0;
			}
			break;
			
	case 10:
		//set custom on_time to eeprom
			if(flag==1)
			{
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
				i2c_byte_write_frame(0xa0,i,n);
				delay_ms(500);
			}
			lcd_cmd(0x1);
			lcd_string("ON_TIME");
			lcd_cmd(0xc0);
			lcd_string("UPDATED");
			}
			else{
			lcd_cmd(0x1);
			lcd_string("LOGIN FIRST");
			}
		break;
			
		case 48:
		//set custom off_time to eeprom
			if(flag==1)
			{
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
				i2c_byte_write_frame(0xa0,i,n);
				delay_ms(500);
			}
			lcd_cmd(0x1);
			lcd_string("OFF_TIME");
			lcd_cmd(0xc0);
			lcd_string("UPDATED");
			}
			else{
			lcd_cmd(0x1);
			lcd_string("LOGIN FIRST");
			}	
			break;
	case 4:
		//to show the current time
			lcd_cmd(0x1);
			rtc(h,m,s);
			break; 
	}
	//again get data from keypad
	temp=keyscan();
}
	pass_light=0;	//pass light turn off when turn on the device even after the login
	lcd_cmd(0x1);
	while(1)
	{
		//rtc function
		h=i2c_byte_read_frame(0xD0,0x2);
		
		m=i2c_byte_read_frame(0xD0,0x1);
		rtc(h,m,s);
		
		HH=(h/16+48);		//0	0	0
		
		hh=(h%16+48);		//0	0	0
		
		MM=(m/16+48);		//1	1	1
			
		mm=(m%16+48);		//0	1	2
		
		//read on time from eeprom
		HH_eeprom=i2c_byte_read_frame(0xa0,0x4);
		delay_ms(100);

		hh_eeprom=i2c_byte_read_frame(0xa0,0x5);
		delay_ms(100);

		MM_eeprom=i2c_byte_read_frame(0xa0,0x6);
		delay_ms(100);

		mm_eeprom=i2c_byte_read_frame(0xa0,0x7);
		delay_ms(100);
		
		//read off time from eeprom
		hh_off_eeprom=i2c_byte_read_frame(0xa0,0x9);
		delay_ms(100);
	
		HH_off_eeprom=i2c_byte_read_frame(0xa0,0x8);
		delay_ms(100);
		
		mm_off_eeprom=i2c_byte_read_frame(0xa0,0xB);
		delay_ms(100);

		MM_off_eeprom=i2c_byte_read_frame(0xa0,0xA);
		delay_ms(100);
		
		//light on or off condtion
		//if current time b/w on and off time light turn on otherwise turn off
			if((HH_eeprom == HH)&&(hh_eeprom==hh)&&(MM_eeprom==MM)&&(mm_eeprom==mm))
				light=1;
			if((HH_off_eeprom == HH)&&(hh_off_eeprom==hh)&&(MM_off_eeprom==MM)&&(mm_off_eeprom==mm))
				light=0;
	}	
}
