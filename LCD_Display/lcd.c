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
void write_int_LCD(signed int num)
{
	int i,count=0;
	char s[3];
	int temp=num;
	while(num>0)
	{
		 count++;
		num=num/10;
	}
	//char s[count];
	for(i=count-1;i>=0;i--)
	{	
		int k=temp%10;
		s[i]=k+48;				//to get the correct ascii value add 48 ascii of zero
		temp=temp/10;
	}
	s[count]='\0';
	i=0;
	while(s[i]!='\0')
	{
		write_dat_LCD(s[i]);
		i++;
	}
}
void write_float_LCD(float f)
{
	int a,b,count_d=0,tempd,i=0;
	char s[30];
	float ff;
	a=f;
	ff=f-a;
	tempd=a;
	while(tempd>0)				//to count the decimal value
	{
		count_d++;
		tempd=tempd/10;
	}
	for(i=count_d-1;i>=0;i--)		//add decimal value to the string
	{
		s[i]=(a%10)+48;			//to get exact digit add zero ascii value 48
		a=a/10;
	}
	//s[count]='\0';
	s[count_d]='.';				//add decimal symbol next to decimal 
	
	
	for(i=1;i<6;i++)			//for add fraction value, precision is set to 5 points only  
	{
		ff=ff*10; 		//.75*10=7.5
		b=ff;			//b=7
		s[count_d+i]=b+48;		//to get exact decimal value add zero ascii value 48
		ff=ff-b;		//7.5-7=.5
	}
	s[count_d+6]='\0';
	//printf("%s\n",s);
		i=0;
	while(s[i]!='\0')
	{
		write_dat_LCD(s[i]);
		i++;
	}
	
}
