//LCD_string_circular_scroll.c
#include "my_header.h"
main(){
	u8 i;
		lcd_init();
		lcd_cmd(0xc);						//cursor off
	for(i=0x80;i<=0x90;i++){
		if(i==0x90)
					i=0x80;
		lcd_cmd(i);				//home position		
		lcd_string("TEST");
		delay_ms(100);
		lcd_cmd(0x1);
	}
	while(1);
}