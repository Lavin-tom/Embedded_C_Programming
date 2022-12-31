//ADC conversion with UART 
#include <xc.h>
#include "config.h"
#define  _XTAL_FREQ  20000000

unsigned char channel_no = 4;

//ADC initialization
void ADC_init()
{
    //avoid channel selection in ADC init()
    ADCON1 = 0x09;              //0b00001001
    ADCON2 = 0x8D;              //enable 2 TAD, FOSC/16, right justification 
   
    ADCON0bits.ADON = 1;        //to enable a/d converter
}

//to selecting for channel selection
unsigned int ADC_convertion(unsigned char channel_no)
{
    unsigned int res_val,templ,temph;
    ADCON0bits.CHS = channel_no;        //selection of channel 
    ADCON0bits.GO_nDONE = 1;             //start conversion
    while(ADCON0bits.GO_nDONE);          //waiting for conversion
     
    //to combine two byte of data into one
    templ = ADRESL;                 //templ = 0x00ff
    temph = ADRESH;                 //temph = 0x0003
    temph = temph  << 8;            //temph = 0x0300 | 0x00ff = 0x03ff
    res_val = temph | templ;
    
    //res_val = ADRESL;
    //res_val | = (unsigned int )ADRESL << 8;     //to combine two integer stored in two bytes of memory
    return  res_val;
}
//to convert hex to bcd
void Hex_to_bcd(unsigned int count,unsigned char *BCDNum)
{
    unsigned int i=0;
    BCDNum[0] = (unsigned char)(count/0x3E8);
    i = count % 0x3E8;
    BCDNum[1] = (unsigned char)(i/0x64);
    i = i % 0x64;
    BCDNum[2] = (unsigned char)(i/0x0A);
    i = i % 0x0A;
    BCDNum[3] = (unsigned char)(i/0x01);
    
}
//to send one bit of data
void tx_data(unsigned char data)
{
        while(TXSTAbits.TRMT==0);
        TXREG = data;
        //TXREG.TRMT=0;
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
//to receive one char
/*unsigned char rx_data()
{
        while(PIR1bits.RCIF==0);
        PIR1bits.RCIF=0;                //for receive next bit
        return RCREG;
}*/

//uart initialization
void uart_init()
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

void main(void) {
    
    unsigned int ADC_result;
    unsigned char ADC_string[4];
    uart_init();
    ADC_init();
    TRISB = 0x00;
    LATB = 0x00;
    unsigned char msg1[]="test of ADC code\r";
    unsigned char msg2[]="ADC result is: \r";
    while(1)
    {
        ADC_result = ADC_convertion(channel_no);
        Hex_to_bcd(ADC_result, ADC_string);
        tx_string(msg2);
        tx_data(ADC_string[0]+0x30);
        tx_data(ADC_string[1]+0x30);
        tx_data(ADC_string[2]+0x30);
        tx_data(ADC_string[3]+0x30);
        tx_data('\r');
        __delay_ms(1000);
    }
    return;
}
