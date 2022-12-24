#include <xc.h>
#include "UART.h"

void UART_Init (void)
{
    TXSTAbits.SYNC = 0;
    TXSTAbits.TX9 = 0;   // Using 8 bit transmission  
    TXSTAbits.TXEN = 1;
    RCSTAbits.RX9 = 0;   // Using 8 bit reception
    RCSTAbits.CREN = 1; 
    BAUDCON = 0x00;
    TXSTAbits.BRGH = 1;
    SPBRG = 129;
    SPBRGH = 0;
    TRISCbits.RC6 =0;
    TRISCbits.RC7 = 1;
    RCSTAbits.SPEN = 1;  
}

void TransmitByte (unsigned char TXbyte)
{
    while(TXSTAbits.TRMT == 0);
    TXREG = TXbyte;
    // TXSTAbits.TRMT = 0;   // Internally performed by uC
    
}

unsigned char ReceiveByte (void)
{
    unsigned char RXbyte;
    while(PIR1bits.RCIF == 0);
    RXbyte = RCREG;
    PIR1bits.RCIF = 0;
    return RXbyte;   
    //return RCREG;
}

void TransmitString (unsigned char *ptr)
{
    while(*ptr != 0)
    {
       TransmitByte(*ptr);
       ptr++;
    }
}