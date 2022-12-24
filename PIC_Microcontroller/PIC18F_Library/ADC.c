#include <xc.h>
#include "ADC.h"

void ADC_Init(void)
{
    ADCON1 = 0b00001000;         
    ADCON2bits.ADFM = 1;        // Right Justified
    ADCON2bits.ADCS = 0b101;    // ADC Clock = Fosc/16
    ADCON2bits.ACQT = 0b001;    // ACQ Time = 2TAD
    ADCON2 = 0b10001101;
    ADCON0bits.ADON = 1;        // Turn on ADC Module
}

unsigned int ADC_Conversion (unsigned char Channel)
{
   unsigned int ADC_Result=0;
    ADCON0bits.CHS = Channel;       // select the channel
    ADCON0bits.GO_nDONE = 1;          // Start Conversion
    while(ADCON0bits.GO_nDONE);
    ADC_Result=ADRESL;
    ADC_Result|=((unsigned int)ADRESH) << 8;
    return ADC_Result;
}


