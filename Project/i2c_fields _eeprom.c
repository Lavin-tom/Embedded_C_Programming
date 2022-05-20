/*i2c_fields_eeprom.c*/
#include<reg51.h>
#include "header.h"
#include <intrins.h>
sbit SDA=P1^0;
sbit SCL=P1^1;

//i2c_start condition
void i2c_start_eeprom(void)
{
	//upon reset 8051 both pins are one 
	SCL=1; //optional
	SDA=1;	//optional
	
	SCL=1;
	SDA=1;
	SDA=0;
}

void i2c_stop_eeprom(void)
{
	SCL=0;
	SDA=0;  
	SCL=1;
	SDA=1;	
}

void i2c_write_eeprom(u8 d)
{
	s8 i;
	for(i=7;i>=0;i--)
	{
	SCL=0;
	SDA=((d>>i)&1);
	SCL=1;
	}
}

u8 i2c_read_eeprom(void)
{
	u8 temp=0x0;
	s8 i;
	for(i=7;i>=0;i--)
	{
		SCL=1;
		if(SDA==1)
			{  
			temp|=(1<<i);
			}
			SCL=0;
	}
	return temp; 
}


bit i2c_ack_eeprom(void)
{
	SCL=0;
	SDA=1;
	SCL=1;	//9th clock pulse
	_nop_(); //macro for 1micro second delay
	_nop_();  //1machine cycle means one micro cycle
	_nop_(); //1mc
	_nop_(); //1mc
if(SDA==0) //means master got ack from the slave
{
	SCL=0;
	return 0;	//upon sucess
}
else
{
	SCL=1 ;
	return 1; 	//upon failure
}
}

void i2c_noack_eeprom(void)
{
	SCL=0;
	SDA=1;
	SCL=1;	//9th clock pulse
}
