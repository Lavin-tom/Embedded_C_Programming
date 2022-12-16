//LCD display integer using functions
#include "my_header.h"
main(){
	s16 num=100;
	lcd_init();
	lcd_cmd(0xc);
	lcd_integer(num);
	while(1);
}