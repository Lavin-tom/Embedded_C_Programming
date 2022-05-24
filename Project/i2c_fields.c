/*i2c_fields.c*/
#include<reg51.h>
#include "header.h"
//header file where _nop_ defined
#include <intrins.h>
sbit SDA=P2^0;
sbit SCL=P2^1;

//i2c_start condition
void i2c_start(void)
{
	//upon reset 8051 both pins are one 
	SCL=1; //optional
	SDA=1;	//optional
	
	SCL=1;
	SDA=1;
	SDA=0;
}

void i2c_stop(void)
{
	SCL=0;
	SDA=0;  
	SCL=1;
	SDA=1;	
}

void i2c_write(u8 d)
{
	s8 i;
	for(i=7;i>=0;i--)
	{
	SCL=0;
	SDA=((d>>i)&1);
	SCL=1;
	}
}

u8 i2c_read(void)
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


bit i2c_ack(void)
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

void i2c_noack(void)
{
	SCL=0;
	SDA=1;
	SCL=1;	//9th clock pulse
}
