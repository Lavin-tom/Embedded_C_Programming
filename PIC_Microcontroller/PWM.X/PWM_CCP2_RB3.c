#include <xc.h>
//Configuration bits setting/
#pragma config OSC = HS //Oscillator Selection
#pragma config WDT = OFF //Disable Watchdog timer
#pragma config LVP = OFF //Disable Low Voltage Programming
#pragma config PBADEN = OFF //Disable PORTB Analog inputs
#pragma config CCP2MX = PORTBE  // CCP2 MUX bit (CCP2 input/output is multiplexed with RB3)

#define _XTAL_FREQ 20000000

void main(void)
{
    TRISBbits.RB3 = 0;
    PR2 = 249;                     //PWM  Frequency 5KHz
    CCP2CONbits.CCP2M = 0b1111;    // PWM Mode
    T2CONbits.T2CKPS = 0b01;        // Prescaler divide by 4
    T2CONbits.TMR2ON = 1;
    CCPR2L = 1;
    CCP2CONbits.DC2B = 0b00;
    while(1)
    {
        for (unsigned char i= 0; i < 250; i += 10)
        {
           CCPR2L = i;
           
           __delay_ms(50);   
        }
            
            
            
    }
    
    
    
}
