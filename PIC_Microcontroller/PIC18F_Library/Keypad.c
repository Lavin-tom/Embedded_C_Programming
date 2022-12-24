#include <xc.h>
#include "Keypad.h"

void Keypad_Init(void)
{
    ADCON1 = 0x0F;          //PORTE as digital input    
    INTCON2bits.RBPU=0;     //To enable the internal pullup
    KEYPAD_TRIS = 0x1F;     //RB7, RB6, RB5 as output  
}
unsigned char Keypad_Scan(void)
{
    unsigned char button = 0;
    
    //Row0 made 0 and columns checked for keypress     
    KEYPAD_LATCH = 0xC0;
    __delay_us(1);   
	if ((KEYPAD_PORT & 0x1E) != 0x1E)
    {
        if((KEYPAD_PORT & 0x1E) == 0x1C) button = 1;    // Pattern for C0 0b00011100                  
        if((KEYPAD_PORT & 0x1E) == 0x1A) button = 2;	// Pattern for C1 0b00011010
        if((KEYPAD_PORT & 0x1E) == 0x16) button = 3;    // Pattern for C2 0b00010110
        if((KEYPAD_PORT & 0x1E) == 0x0E) button = 4;	// Pattern for C3 0b00001110			
        return button;               
	}
    
    //Row1 made 0 and columns checked for keypress
    KEYPAD_LATCH = 0xA0;     // 0b10100000
    __delay_us(1);	   
    if ((KEYPAD_PORT & 0x1E) != 0x1E)
    {
        if((KEYPAD_PORT & 0x1E) == 0x1C) button = 5;    // Pattern for C0 0b00011100               
        if((KEYPAD_PORT & 0x1E) == 0x1A) button = 6;	// Pattern for C1 0b00011010	  
        if((KEYPAD_PORT & 0x1E) == 0x16) button = 7;    // Pattern for C2 0b00010110
        if((KEYPAD_PORT & 0x1E) == 0x0E) button = 8;	// Pattern for C3 0b00001110			                   
        return button;
    }
    
      //Row2 made 0 and columns checked for key press     
    KEYPAD_LATCH  = 0x60;
    __delay_us(1);       
    if ((KEYPAD_PORT & 0x1E) != 0x1E)
    {
        if((KEYPAD_PORT & 0x1E) == 0x1C) button = 9;    // Pattern for C0 0b00011100                  
        if((KEYPAD_PORT & 0x1E) == 0x1A) button = 10;	// Pattern for C1 0b00011010
        if((KEYPAD_PORT & 0x1E) == 0x16) button = 11;   // Pattern for C2 0b00010110
        if((KEYPAD_PORT & 0x1E) == 0x0E) button = 12;	// Pattern for C3 0b00001110
        return button;
    }	
    return button;
}


unsigned char Get_Key(void)  
{
    unsigned char but1, but2, Key;
	but1 = Keypad_Scan();
    __delay_ms(250);         //Debounce time of 40ms
    but2 = Keypad_Scan();
    
    if(but1==but2)
    {
        Key = KeyVal[but1];
        return(Key); 
    }
    else
    {
        Key = KeyVal[but1];
        return(Key);
    }
}
