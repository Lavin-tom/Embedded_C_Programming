//seven segment multiplexer
#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 20000000

unsigned char BCDNum[4];
unsigned int count,val=0;
const char seg_data[]={ 0b11100111,         //0
                        0b00100001,         //1
                        0b11001011,         //2
                        0b01101011,         //3    
                        0b00101101,         //4
                        0b01101110,         //5
                        0b11101100,         //6
                        0b00100011,         //7
                        0b11101111,         //8
                        0b01101111};        //9   
void Timer0_Init(void)
{
    T0CONbits.T0CS = 0;             //select clock source
    T0CONbits.T08BIT = 0;           //16 bit select mode selected
    T0CONbits.PSA = 1;              //prescalar is not assigned
    T0CONbits.T0PS = 0b000;         //to select prescalar range 
    TMR0H = 0xCF;                   //load initial values
    TMR0L = 0x2B;   
    
    RCONbits.IPEN = 0;          //selecting legacy mode
    INTCONbits.TMR0IF = 0;      //interrupt flag clear
    INTCONbits.TMR0IE = 1;      //interrupt enable
    INTCONbits.GIE = 1;         //global interrupt enable
    T0CONbits.TMR0ON = 1;       //timer on
}
void GPIO_Init(void)
{
    ADCON1 = 0x0F;  //set to digital 
    TRISD = 0x00;   //set port D as output
    TRISA = 0xF0;   //set port A as output
}
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

void seg_multi(void)
{
    
    switch(val)
    {
        case 0: 
            PORTD = seg_data[BCDNum[0]];
            PORTA = 0x01;
            break;
        case 1:
            PORTD = seg_data[BCDNum[1]];
            PORTA = 0x02;
            break;
        case 2:
            PORTD = seg_data[BCDNum[2]];
            PORTA = 0x04;
            break;
        case 3:
            PORTD = seg_data[BCDNum[3]];
            PORTA = 0x08;
            break;                
    }
    val++;
    if(val>3)
        val = 0;
}
void __interrupt(high_priority) seg_display(void)
{
    if(INTCONbits.TMR0IF)
    {
        INTCONbits.TMR0IF=0;        //clear interrupt flag
        TMR0H = 0xcf;               //load initial value
        TMR0L = 0x2b;
        seg_multi();
    }
}
void main(void) {
    
    GPIO_Init();                //initialization of General purpose i/o
    Timer0_Init();              //timer0 initialization
    count=0;
    while(1)
    {
        count++;
        if(count>9999)
            count=0;
        Hex_to_bcd(count,BCDNum);
        __delay_ms(100);
    }
    return;
}
