//seven segment display with key debouncing concept

#include <xc.h>

#define _XTAL_FREQ 20000000

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

#define UP_SW   PORTCbits.RC0
#define DN_SW   PORTCbits.RC1

void main (void)
{
    signed char i=0;
    ADCON1= 0x0F;
    TRISD = 0x00;
    TRISAbits.RA0 = 0;
    LATAbits.LA0 = 1;
    
    TRISAbits.RA1 = 0;
    LATAbits.LA1 = 1;
    
    TRISAbits.RA2 = 0;
    LATAbits.LA2 = 1;
    
    TRISAbits.RA3 = 0;
    LATAbits.LA3 = 1;
    while(1)
    {
        if(UP_SW == 0)
        {
            __delay_ms(200);
            if (UP_SW == 0)
            {
                i++;
                if (i>9)   i = 0;
                PORTD = seg_data[i];
            }
        }
        if(DN_SW == 0)
        {
            __delay_ms(200);
            if (DN_SW == 0)
            {
                i--;
                if (i < 0)   i = 9;
                PORTD = seg_data[i];
            }
        }
    }
   
}