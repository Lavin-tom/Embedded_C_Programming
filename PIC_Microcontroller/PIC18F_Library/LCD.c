#include <xc.h>
#include "LCD.h"

//Function Definitions
//void msdelay (unsigned int time) //Function to generate delay
//{
//unsigned int i, j;
//  for (i = 0; i < time; i++)
//	for (j = 0; j < 275; j++);//Calibrated for a 1 ms delay in MPLAB
//}


void LCD_Init(void)		// Function to initialise the LCD
{
    LCD_DATA_DDR = 0;
    LCD_RS_DDR = 0;
    LCD_RW_DDR = 0; 
    LCD_EN_DDR = 0;
    
    LCD_Command(0x38);      // initialization of 16X2 LCD in 8bit mode
    __delay_ms(5);
    LCD_Command(0x06);      // Cursor shift 
    __delay_ms(5);
    LCD_Command(0x0C);      // Display on cursor off
    __delay_ms(5);
    LCD_Command(0x01);      // clear LCD
    __delay_ms(5);
    LCD_Command(0x80);      // go to first line and 0th position
    __delay_ms(5);
}

void LCD_Command(unsigned char cmd) //Function to pass command to the LCD
{
    LCD_DATA = cmd;         //Send data on LCD data bus
    LCD_RS = 0;				//RS = 0 since command to LCD
    LCD_RW = 0;				//RW = 0 since writing to LCD
    LCD_EN = 1;				//Generate High to low pulse on EN
    __delay_ms(5);
    LCD_EN = 0;
}

void LCD_Data(unsigned char data)//Function to write data to the LCD
{
    LCD_DATA = data;	//Send data on LCD data bus
    LCD_RS = 1;				//RS = 1 since data to LCD
    LCD_RW = 0;				//RW = 0 since writing to LCD
    LCD_EN = 1;				//Generate High to low pulse on EN
  	__delay_ms(5);
    LCD_EN = 0;
}
//Function to write string to LCD
void LCD_RAM_String(unsigned char *str)   
{
    int i = 0;
    while (str[i] != 0)
    {
        LCD_Data(str[i]);      // sending data on LCD byte by byte
        __delay_ms(5);
        i++;
    }
}

void LCD_ROM_String(const char *str)   
{
    int i = 0;
    while (str[i] != 0)
    {
        LCD_Data(str[i]);      // sending data on LCD byte by byte
        __delay_ms(15);
        i++;
    }
}

