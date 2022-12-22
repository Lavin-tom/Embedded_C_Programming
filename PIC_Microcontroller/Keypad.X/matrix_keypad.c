//matrix keypad main
#include "Config.h"
#include <xc.h>
#include "LCD.h"
#include "Keypad.h"

const char msg1[] = "Matrix Keypad";
const char msg2[] = "Key pressed : ";

void main(void) {
    
    unsigned char Key;
    LCD_Init();
    Keypad_Init();
    LCD_ROM_String(msg1);
    LCD_Command(0xC0);
    LCD_ROM_String(msg2);
    // __delay_ms(1000);
    //LCD_Command(0x1);
    //unsigned char i=0;
    while(1)
    {
        while((Key = Get_Key()) == 'N');
        //__delay_ms(1000);
        //LCD_Command(0x1);
        LCD_Command(0xCD);
        LCD_Data(Key);
        // LCD_Command(0x80+i);
        //i++;
    }
    return;
}
