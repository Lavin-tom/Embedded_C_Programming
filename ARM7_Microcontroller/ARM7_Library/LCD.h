//header file of LCD

#ifndef LCD_H		//to avoid multiple definition problem
#define LCD_H

#define LCD_Data_Dir	IODIR0 |= 0x0F << 10
#define LCD_Cntrl_Dir	IODIR1 |= 0x0F << 21

//RS pin of LCD
#define LCD_RS_Set		IOSET1 = 1 << 24
#define LCD_RS_Clear	IOCLR1 = 1 << 24

//RW pin of LCD
#define LCD_RW_Set		IOSET1 = 1 << 23
#define LCD_RW_Clear	IOCLR1 = 1 << 23

//EN Pin of LCD
#define LCD_EN_Set		IOSET1 = 1 << 22
#define LCD_EN_Clear 	IOCLR1 = 1 << 22

//Backlight of LCD
#define LCD_BL_On		IOSET1 = 1 << 21
#define LCD_BL_Off 		IOCLR1 = 1 << 21

//to send data
#define LCD_Data_Set	IOSET0	= LCDVAL << 10
#define LCD_Data_Clear	IOCLR0 = 0x0F << 10

void delay_ms(unsigned int time);
void LCD_Command(unsigned char Command);
void LCD_Data(unsigned char	Data);
void LCD_Init(void);
void LCD_String(unsigned char *string);

#endif 



