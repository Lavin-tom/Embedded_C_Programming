//RTC - Real time clock - I2C 
//RTC1307
#include <xc.h>
#include "Config.h"
#include "I2C.h"
#include "LCD.h"
#include "Keypad.h"

#define __XTAL_FREQ 20000000
unsigned char date[] = "Date:",month[] = "Month:",time[]="Time:";
unsigned char RTC_flag=0;
unsigned char RTC_start=0;
//user defined time format
unsigned char userTime [] = {
    
    //BCD format only
    0b00000001,         //1          sec
    0b00010000,         //10         min
    0b00011000,         //18         hr   //24 hr format
    0b00000110,         //6         day     friday
    0b00010110,         //16        day of month
    0b00010010,         //12        month
    0b00100010         //22        year
};
unsigned char RTCTime[7];
void BCD_to_ASCII_Display(unsigned char Digit)
{
    unsigned char temp;
   
    /*temp = temp/10;             //1
    
    Digit = Digit%10;           //8
    
    temp=temp*10;
    //temp=temp+48;
    Digit = Digit +temp;
    
    Digit = Digit+48;*/
    
    temp = Digit;
    temp = (temp & 0xF0) >> 4;
    temp = temp | 0x30;
    LCD_Data(temp);
    
    temp = Digit;
    temp = (temp & 0x0F);
    temp = temp| 0x30;
    LCD_Data(temp);
    
}
//RTC Initialization
RTC_init()
{
    RTC_flag=1;
    I2C_Byte_Write(0xA0,0x10,RTC_flag);
    I2C_Page_Write(0xD0, 0x00, userTime, 7);
    __delay_ms(10);
}
//Read from EEPROM
RTC_read()
{
    I2C_Page_Read(0xD0, 0x00, RTCTime, 7);
    //date
    LCD_Command(0x85);          //move cursor to appropriate after "Date"
    BCD_to_ASCII_Display(RTCTime[4]);
    LCD_Data('/');
    BCD_to_ASCII_Display(RTCTime[5]);
    LCD_Data('/');
    BCD_to_ASCII_Display(0x20);
    BCD_to_ASCII_Display(RTCTime[6]);
    
    
    //time
    LCD_Command(0xC5);
    BCD_to_ASCII_Display(RTCTime[2]);
    LCD_Data(':');
    BCD_to_ASCII_Display(RTCTime[1]);
    LCD_Data(':');
    BCD_to_ASCII_Display(RTCTime[0]);
    //__delay_ms(1000);                      //to avoid unwanted execution under 1 sec
    
    //to save data into eeprom
 //   for(unsigned char i=0;i<7;i++)
 //   {
 //   I2C_Page_Write(0xA0, 0x10, RTCTime,7);
 //   __delay_ms(10);
  //  }
    
}

void main(void) {
    
    I2C_Init();
    LCD_Init();
    
    RTC_start = I2C_Byte_Read(0xD0, 0x00);          //checking the status of ch bits from RTC
    RTC_start = RTC_start & 0x80;                   //check the status of first bit
    RTC_flag= I2C_Byte_Read(0xA0,0x10);
    
    //RTC is not init OR RTC is not start
    //if((RTC_flag == 0))
    if((RTC_flag != 1) || (RTC_start != 0))             //initialization done only when RTC is not initialized
        RTC_init();
    
    LCD_ROM_String(date);
    LCD_Command(0xC0);
    LCD_ROM_String(time);
    unsigned char Key;
        RTC_read();
        I2C_Page_Read(0xA0, 0x10,RTCTime,7);
    Keypad_Init();
    
    while(1)
    {
        unsigned char i;
        RTC_read();
        for(i=0;i<20;i++)
        {
            Key = Get_Key();
            if(Key != 'N')
             {
                LCD_Command(0xCF);
                LCD_Data(Key);
                break;
            }
        }
    }
    return;
}
