//LCD set counter and down counter
#include "my_header.h"
main(){
	s8 temp=0;
	lcd_init();
	lcd_cmd(0xc);
		while(1){
			if(io_bit_read(PORT2,0)==0){
					lcd_cmd(0x80);
					lcd_data((temp/10)+48);
					lcd_data((temp%10)+48);
					temp+=1;
					while(io_bit_read(PORT2,0)==0);
		}
		if(io_bit_read(PORT2,1)==0){
			while(temp>0){
				temp-=1;
				lcd_cmd(0x80);
				lcd_data((temp/10)+48);
				lcd_data((temp%10)+48);
				delay_ms(100);
				}
			}
		}
}