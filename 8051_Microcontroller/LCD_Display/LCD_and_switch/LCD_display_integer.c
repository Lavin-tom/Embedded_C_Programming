//LCD_display_integer.c
#include "my_header.h"
main(){
	u8 d=0,sum=0,a=123;
	lcd_init();
	lcd_cmd(0x0c);
	while(a>0){
	d=a%10;
	sum=sum*10+d;
	a/=10;
	}
	
	while(sum>0){
	d=sum%10;
	lcd_data(d+48);
	sum/=10;
	}
	while(1);			//avoid infinity loop
}