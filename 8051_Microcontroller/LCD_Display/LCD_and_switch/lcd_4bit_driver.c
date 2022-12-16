//lcd4bit_driver.c
#include <reg51.h>
#include "my_header.h"
sbit RS=P0^4;
sbit RW=P0^5;
sbit EN=P0^6;
//to print integer value in LCD
void lcd_integer(s16 num)
{
	u8 d,count1=0,count2=0;
	s16 sum=0;
	if(num<0){							//check for neagative no
		num=num*-1;						
		lcd_data(45);					//-ve sign equalent ascii value
	}
	if(num==0){
		lcd_data(48);
	}
	while(num>0){						//to reverse the actual no
		d=num%10;
		sum=sum*10+d;
		num/=10;
		count1++;
	}
	while(sum>0){						//printing the integer
		d=sum%10;
		lcd_data(d+48);
		count2++;
		sum/=10;
	}
	while(count1!=count2){	//to create exact no of zeros
			lcd_data(48);
			count2++;
	}
}
//to print float values
void lcd_float(f32 a){
	f32 c;
	s8 b=(int)a;
	if(b<0){							//check for neagative no
		b=b*-1;						
		lcd_data(45);					//-ve sign equalent ascii value
	}
	lcd_integer(b);
	lcd_data(46);
	c=a-b;
	c=c*10;
	b=c;
	lcd_data(b+48);
}
//to print single char on the lcd
void lcd_data(u8 d)
{
		P0=d>>4;
		RS=1;
		RW=0;
		EN=1;
		delay_ms(2);	//mandatory to provide delay
		EN=0;					//for next operation
	
		P0=d&0x0F;
		RS=1;
		RW=0;
		EN=1;
		delay_ms(2);
		EN=0;
}
//to print string in LCD
void lcd_string(u8 *ptr){
	while(*ptr!=0){
		lcd_data(*ptr);
		ptr++;
	}
}
//to write single command on the LCD
void lcd_cmd(u8 c)
{
		P0=c>>4;
		RS=0;
		RW=0;
		EN=1;
		delay_ms(2);
		EN=0;
	
		P0=c&0x0F;
		RS=0;
		RW=0;
		EN=1;
		delay_ms(2);
		EN=0;
}
//to lcd initialization
void lcd_init(void)
{
		lcd_cmd(0x2);		//don't clear and set curson home position
		lcd_cmd(0x28);	//initialize 4 bit LCD
		lcd_cmd(0xE);		//turn on the cursor
		lcd_cmd(0x1);		//clear LCD and set cursor on home position	
}