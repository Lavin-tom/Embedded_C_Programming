//EEPROM - SPI

#include "Config.h"
#include "LCD.h"
#include <xc.h>

#define CS_EEPROM_TRIS TRISCbits.RC2
#define CS_EEPROM_HIGH PORTCbits.RC2 = 1;
#define CS_EEPROM_LOW  PORTCbits.RC2 = 0;

#define write_enable    (unsigned)0b00000110
#define write_disable   (unsigned)0b00000100
#define write_cmd       (unsigned)0b00000010
#define read_cmd        (unsigned)0b00000011
#define read_status     (unsigned)0b00000101
#define write_status    (unsigned)0b00000001
void SPI_Init()
{
    SSPCON1bits.SSPM = 0b001;           //SPI clock = FOSC/16
    SSPCON1bits.CKP = 0;
    SSPSTATbits.SMP = 1;
    SSPSTATbits.CKE = 1;
    
    CS_EEPROM_TRIS =0;
    CS_EEPROM_HIGH;
    TRISCbits.RC5 = 0;              //SDO as output
    TRISCbits.RC4 = 1;              //SDI as input
    TRISCbits.RC3 = 0;              //SCK as output
    SSPCON1bits.SSPEN = 1;           //SSP (SPI)  Enable
}
unsigned char SPI_Read_Write(unsigned char val)
{
    SSPBUF = val;
    while(!PIR1bits.SSPIF);
    PIR1bits.SSPIF=0;
    return SSPBUF;
}
void SPI_EEPROM_writebyte(unsigned int addr, unsigned char data)
{
    unsigned char Higher_byte, Lower_byte;
    
    //split add into lower and hight bytes
    Higher_byte = (unsigned char) addr>>8;
    Lower_byte = (unsigned char) addr;
    
    CS_EEPROM_LOW;         //enable write option
    SPI_Read_Write(write_enable);
    CS_EEPROM_HIGH;
    
    __delay_us(100);            //to provide micro second delay
    
    CS_EEPROM_LOW;
    SPI_Read_Write(write_cmd);
    SPI_Read_Write(Higher_byte);
    SPI_Read_Write(Lower_byte);
    
    SPI_Read_Write(data);
    
    CS_EEPROM_HIGH;
    
    __delay_ms(20);           //wait for completion of writing
    
    SPI_Read_Write(write_disable);
}
unsigned char SPI_EEPROM_readbyte(unsigned int addr)
{
    unsigned char Higher_byte, Lower_byte, Read_val;
    
    CS_EEPROM_LOW;         //enable write option
    SPI_Read_Write(read_cmd);
    SPI_Read_Write(Higher_byte);
    SPI_Read_Write(Lower_byte);
    
    Read_val = SPI_Read_Write(0xff);     //dummy data to send
    CS_EEPROM_HIGH;
    
    return Read_val;
}
unsigned char msg[]="SPI EEPROM is working";
void main(void) {
    unsigned char read_val=0;
    LCD_Init();
    LCD_ROM_String(msg);
    LCD_Command(0xc0);
    SPI_Init();
    
    SPI_EEPROM_writebyte(0x123, 'O');
    SPI_EEPROM_writebyte(0x200, 'T');
    SPI_EEPROM_writebyte(0x300, 'L');
    
    read_val = SPI_EEPROM_readbyte(0x123);
    LCD_Data(read_val);
    read_val = SPI_EEPROM_readbyte(0x200);
    LCD_Data(read_val);
    read_val = SPI_EEPROM_readbyte(0x300);
    LCD_Data(read_val);
    return;
}
