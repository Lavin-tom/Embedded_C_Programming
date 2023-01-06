#include <xc.h>
#include "config.h"

typedef unsigned char u8;
#define RS LATCbits.LC1
#define RW LATCbits.LC0
#define EN LATCbits.LC2
#define P0 PORTD 
#define _XTAL_FREQ 20000000

//to print single char on the lcd
void lcd_data(u8 d)
{
		P0=d;
		RS=1;
		RW=0;
		EN=1;
		__delay_ms(2);          //mandatory to provide delay
		EN=0;					//for next operation
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
		P0=c;
		RS=0;
		RW=0;
		EN=1;
		__delay_ms(2);
		EN=0;
}
void lcd_init(void)
{
		lcd_cmd(0x2);		//don't clear and set curson home position
		lcd_cmd(0x38);      //initialize 8 bit LCD
		lcd_cmd(0xE);		//turn on the cursor
        lcd_cmd(0x6);
		lcd_cmd(0x1);		//clear LCD and set cursor on home position	
}
void main(void) {
    TRISD = 0x00;   //set port D as output
    TRISC = 0x00;   //set port C as output
    
    lcd_init();
    lcd_cmd(0xc);
    lcd_cmd(0x80);
    //lcd_data(65);
    for(u8 i=0;i<16;i++)
    {
        lcd_cmd(0x80+i);        //home position 
        lcd_string("Hello World!");
        __delay_ms(200);
        lcd_cmd(0x1);
    }
    return;
}
