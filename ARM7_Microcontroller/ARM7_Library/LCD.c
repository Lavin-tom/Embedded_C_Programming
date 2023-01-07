//LCD.c
#include<lpc214x.h>
#include "LCD.h"

//delay function definition
void delay_ms(unsigned int time)
{
	unsigned int i,j;
	for(i=0;i<time;i++)
	{
		for(j=0;j<8000;j++);
	}
}
void LCD_Command(unsigned char Command)
{
	unsigned char LCDVAL;
	//sending higher bits
	LCD_RS_Clear;
	LCD_RW_Clear;
	LCDVAL = (Command >> 4) & (0x0F);
	LCD_Data_Clear;
	LCD_Data_Set;

	LCD_EN_Set;
	delay_ms(5);
	LCD_EN_Clear;

	//sending lower bit
	LCDVAL = (Command & 0x0F);
	LCD_Data_Clear;
	LCD_Data_Set;
	LCD_EN_Set;
	delay_ms(5);
	LCD_EN_Clear;
}
void LCD_Data(unsigned char Data)
{
	unsigned char LCDVAL;
	//sending higher bits
	LCD_RS_Set;
	LCD_RW_Clear;

	LCDVAL = (Data >> 4) & (0x0F);
	LCD_Data_Clear;
	LCD_Data_Set;
	LCD_EN_Set;
	delay_ms(5);
	LCD_EN_Clear;

	//sending lower bit
	LCDVAL = (Data & 0x0F);
	LCD_Data_Clear;
	LCD_Data_Set;
	LCD_EN_Set;
	delay_ms(5);
	LCD_EN_Clear;
}
//to lcd initialization
void LCD_Init(void)
{
		LCD_Data_Dir;
		LCD_Cntrl_Dir;
		LCD_BL_On;
		LCD_Command(0x33);		//configure the LCD in 4 bit according to the data sheet of LCD
		delay_ms(5);
		LCD_Command(0x32);
		delay_ms(5);

		LCD_Command(0x2);		//don't clear and set curson home position
		LCD_Command(0x28);		//initialize 4 bit LCD
		delay_ms(50);			//by default LCD is in 8 bit
		LCD_Command(0xE);		//turn on the cursor
		LCD_Command(0x1);		//clear LCD and set cursor on home position	
}

//to print string in LCD
void LCD_String(unsigned char *string){
	while(*string!=0){
		LCD_Data(*string);
		string++;
	}
}
