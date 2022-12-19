#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 20000000
uart_init()
{
   TXSTAbits.SYNC =0;
   TXSTAbits.TX9 = 0;            //using 8 bit
   TXSTAbits.TXEN = 1;
   TXSTAbits.BRGH = 1;
   
   RCSTAbits.CREN = 1 ;
   RCSTAbits.RX9 = 0;           //using 8 bit reception
   RCSTAbits.SPEN = 1;
   
   BAUDCON = 0x00;
   SPBRG = 129;
   SPBRGH = 0;
   TRISCbits.RC6 = 0;           //setting output
   TRISCbits.RC7 = 1;           //setting as input
}

//to transmit one char
tx_data(unsigned char data)
{
        while(TXSTAbits.TRMT==0);
        TXREG = data;
        //TXREG.TRMT=0;
}
//to receive one char
unsigned char rx_data()
{
        while(PIR1bits.RCIF==0);
        PIR1bits.RCIF=0;                //for receive next bit
        return RCREG;
}
//to send one string
void tx_string(unsigned char *ptr)
{
    while(*ptr!=0)
    {
        tx_data(*ptr);
        ptr++;
    }
}
void main(void) {
    TRISB=0;
    unsigned char data='A',received_data;
    unsigned char msg1[]="\rtesting of uart\r";
    unsigned char msg2[]="yes its working\r";
    PORTB=0x0;
    uart_init();
    while(1)
    {
        received_data=rx_data();
        switch(received_data-48)
        {
            case 0:
                PORTB= 0x0;
                 break;    
            case 1:
                PORTB=0x0;
                LATBbits.LB0 = 1;
                break;
            case 2:
                PORTB= 0x0;
                LATBbits.LB1 = 1;
                break;
            case 3:
                   PORTB= 0x0;
                LATBbits.LB2 = 1;
                break;
            case 4:
                PORTB= 0x0;
                LATBbits.LB3 = 1;
                break;
            case 5:
                PORTB= 0x0;
                LATBbits.LB4 = 1;
                break;
            case 6:
                PORTB= 0x0;
                LATBbits.LB5 = 1;
                break;
            case 7:
                PORTB= 0x0;
                LATBbits.LB6 = 1;
                break;
            case 8:
                PORTB= 0x0;
                LATBbits.LB7 = 1;
                break;
            case 9:
                PORTB=0xFF;
        }
    }
    return;
}
