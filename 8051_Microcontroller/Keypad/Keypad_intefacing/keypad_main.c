//keypad main.c
#include "my_header.h"
main(){
	u8 temp;
	lcd_init();
	while(1){
		temp=keyscan();
		lcd_data(temp+48);
	 }
}