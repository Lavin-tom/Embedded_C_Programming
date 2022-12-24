#ifndef __SEG7_H
#define __SEG7_H

#define SEG_ON_TIME (10*1)     //Specifies ON time in terms of millisecond in multiples of 5
#define SEG7_PORT PORTD 
#define SEG7_TRIS TRISD

#define ENABLE0 PORTAbits.RA3
#define ENABLE1 PORTAbits.RA2
#define ENABLE2 PORTAbits.RA1
#define ENABLE3 PORTAbits.RA0

#define EN0_TRIS TRISAbits.TRISA3
#define EN1_TRIS TRISAbits.TRISA2
#define EN2_TRIS TRISAbits.TRISA1
#define EN3_TRIS TRISAbits.TRISA0

#define SegClose() SEG7_PORT=0xFF

void Seg_Init(void);          //Used to initialize the ports used up by display
void Put_7Seg(unsigned int);  //Used to write Numerical value used by 7 seg display
void SegMultiplex(void);     //Used to give Multiplexing action
  
#endif
