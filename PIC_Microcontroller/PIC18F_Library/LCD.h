/* 
 * File:   LCD.h
 * Author: shree
 *
 * Created on April 30, 2022, 9:14 PM
 */

#ifndef LCD_H
#define	LCD_H

#define _XTAL_FREQ                  20000000

#define LCD_DATA_DDR    TRISD
#define LCD_RS_DDR      TRISCbits.RC1
#define LCD_RW_DDR      TRISCbits.RC0
#define LCD_EN_DDR      TRISCbits.RC2

#define LCD_DATA        LATD
#define LCD_RS          LATCbits.LATC1 
#define LCD_RW          LATCbits.LATC0
#define LCD_EN          LATCbits.LATC2

void LCD_Init(void);                        //Function to Initialize the LCD		
void LCD_Command(unsigned char cmd);        //Function to Pass Command to the LCD
void LCD_Data(unsigned char data);          //Function to Write character to the LCD
void LCD_RAM_String(unsigned char *str);    //Function to Write RAM string to the LCD
void LCD_ROM_String(const char *str);       //Function to Write ROM string to the LCD

#endif	/* LCD_H */

