#include<xc.h>
#include "config.h"
void Timer1_Init() {
    T1CONbits.RD16=0;         //to select clock source     
    T1CONbits.TMR1CS =0;          //to set clock source fosc/4          
    T1CONbits.T1CKPS =0b11;     //prescale assign
    
    //T1CON = 0b00110000;
    
    TMR1H   = 0x3C;             //load values higher
    TMR1L   = 0xAF;             //load values to lower
    T1CONbits.TMR1ON = 1;       //timer0 on
}
void timer1()
{
        while(PIR1bits.TMR1IF==0);
        T1CONbits.TMR1ON = 0;        //stop timer
        PIR1bits.TMR1IF==0;         //clear overflow flag
        TMR0H = 0x3C;               //reload value
        TMR0L = 0xAF;
        T1CONbits.TMR1ON = 1;       //timer0 on
}
void main()
{
    TRISBbits.RB7 = 0;      //set as output
    LATBbits.LATB7 = 0;
    Timer1_Init();
    while(1)
    {
        LATBbits.LATB7 = 0;
        timer1();
        LATBbits.LB7 = 1;
        timer1();
        
    }
}