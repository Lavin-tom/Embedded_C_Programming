#include<reg51.h>
#include"delay.h"
#include"lcd.h"
#define LCD_DAT P0
sbit rs=P2^0;
sbit rw=P2^1;
sbit en=P2^2;
//void delay_ms(unsigned int Tdly_ms);
void Init_LCD(void)
{
	delay_ms(16);//
	write_cmd_LCD(0x30);
	delay_ms(6);
	write_cmd_LCD(0x30);
	delay_ms(1);
	write_cmd_LCD(0x30);//selects 8-bit interface mode
	delay_ms(1);
	write_cmd_LCD(0x38);//selects 8-bit interface,5X7 font and 2 disp lines mode
	write_cmd_LCD(0x10);//Turn off the display
	write_cmd_LCD(0x01);//to clear the display
	write_cmd_LCD(0x06);//Inc the cursor after each byte wriiten on to the disp
	write_cmd_LCD(0x0f);//Display ON,cursor ON with blinking			
}
void write_cmd_LCD(char cmd)
{
	rw=0;//writing on to the LCD
	LCD_DAT=cmd;
	rs=0;//Selects Instruction register
	en=1;en=0;//Falling edge on en latched on to the disp
	delay_ms(2);
}
void write_dat_LCD(char dat)
{
	rw=0;//writing on to the LCD
	LCD_DAT=dat;
	rs=1;//selects data register
	en=1;en=0;//Falling edge on en latched on to the disp
	delay_ms(2);
	
}
//place into code memory of uC
char code a[]={0x1d,0x05,0x05,0x1f,0x14,0x14,0x17,0x00};
void store_font_CGRAM(void)
{
	char i;
	write_cmd_LCD(0x40);//cursor is into CGRAM
	for(i=0;i<8;i++)
		write_dat_LCD(a[i]);
}