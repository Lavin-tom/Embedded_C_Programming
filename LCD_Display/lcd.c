#include<reg51.h>
#include"delay.h"
#include"lcd.h"
#define LCD_DAT P0
sbit rs=P2^0;
sbit rw=P2^1;
sbit en=P2^2;
void delay_ms(unsigned int Tdly_ms);
//LCD initialization according to the manufacture's data sheet
void Init_LCD (void)
{
	delay_ms(16);
	write_cmd_LCD(0x30);
	delay_ms(6);
	//select 8 bit interface mode
	write_cmd_LCD(0x30);
	delay_ms(1);
	write_cmd_LCD(0x30);
	delay_ms(1);
	//select 8-bit interface,5x7 font and 2 disp mode 
	write_cmd_LCD(0x38);
	//turn off the display
	write_cmd_LCD(0x10);
	//to clear the display
	write_cmd_LCD(0x01);
	//Inc the curson after each byte writen on to the display
	write_cmd_LCD(0x06);
	//Display ON, curson ON with blinking
	write_cmd_LCD(0x0f);
}
void write_cmd_LCD(char cmd)
{
	rw=0;		//writing on to the LCD
	LCD_DAT=cmd;
	rs=0;		//selects Instruction register
	en=1;
	en=0;		//falling edge on en lached on the display
	delay_ms(2);
}

void write_dat_LCD(char dat)
{
	rw=0;		//writing on to the LCD
	LCD_DAT=dat;
	rs=1;
	en=1;
	en=0;		//falling edge on en lached on the display
	delay_ms(2);
}
void write_str_LCD(char *ptr)
{
	while(*ptr!='\0')
		write_dat_LCD(*ptr++);
}
