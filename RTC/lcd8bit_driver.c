#include <reg51.h>
#include "header.h"
sbit RS=P2^5;
sbit RE=P2^6;
sbit EN=P2^7;

#define LCD_Data P0

//to print single character on LCD
void lcd_data(u8 d)
{
	LCD_Data=d;
	RS=1;
	RE=0;
	EN=1;
	//mandatory for smooth operation
	delay_ms(2);
	EN=0;
}

//write single command
void lcd_cmd(u8 c)
{
	LCD_Data=c;
	RS=0;
	RE=0;
	EN=1;
	delay_ms(2);
	EN=0;
}
/*write string on display*/
void lcd_string(s8 *ptr)
{
	while(*ptr!='\0')
	{
		lcd_data(*ptr);
		ptr++;
	}
}

//LCD initialization
void lcd_init(void)
{
	//cmd for set the cursor for home position
	lcd_cmd(0x2);

	//select 8 bit mode
	lcd_cmd(0x38);

	//turn on the cursor
	lcd_cmd(0xE);

	//clear the LCD screen
	lcd_cmd(0x1);	
}