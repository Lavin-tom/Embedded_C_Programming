#include <xc.h>
#include "config.h"

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
    unsigned char data='A',received_data;
    unsigned char msg1[]="\rtesting of uart\r";
    unsigned char msg2[]="yes its working\r";
   
    uart_init();
    
    tx_data(data);
    tx_string(msg1);
    tx_string(msg2);
    
    received_data=rx_data();
    tx_data(received_data);
    while(1);
    return;
}
