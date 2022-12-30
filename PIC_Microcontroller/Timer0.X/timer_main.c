#include <xc.h>
#include "config.h"

void Timer0_Init() {
    T0CONbits.T08BIT=0;         //to select 16bit     
    T0CONbits.T0CS =0;          //to set clock source fosc/4          
    T0CONbits.T0SE =0;          //set source edge as falling edge
    T0CONbits.PSA = 0;          //prescale assign
    T0CONbits.T0PS = 0b010;     //prescalar to timer range 8
    TMR0H   = 0x0B;             //load values higher
    TMR0L   = 0xDB;             //load values to lower
    T0CONbits.TMR0ON = 1;       //timer0 on
}
void Timer0(){
        while(INTCONbits.TMR0IF==0);
        T0CONbits.TMR0ON = 0;        //stop timer
        INTCONbits.TMR0IF = 0;       //clear overflow flag
        TMR0H = 0x0B;               //reload value
        TMR0L = 0xDB;
        T0CONbits.TMR0ON = 1;       //timer0 on
}
void main(void)
{
    TRISBbits.RB0 = 0;
    LATBbits.LB0 = 0;
    Timer0_Init();
    while(1)
    {
        LATBbits.LB0 = 0;              //led turn off
        Timer0();
        LATBbits.LB0 = 1;              //led turn on
        Timer0();
    }
}
