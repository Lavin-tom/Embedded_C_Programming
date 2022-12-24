#ifndef __Keypad_H
#define __Keypad_H

#define _XTAL_FREQ          20000000 

#define KEYPAD_TRIS     TRISB
#define KEYPAD_PORT     PORTB
#define KEYPAD_LATCH    LATB


unsigned char KeyVal[]={'N',                // No Key Pressed
                        '1','2','3','4',    // Row0 Key pressed
                        '5','6','7','8',    // Row1 Key pressed
                        '9','A','B','C'     // Row2 Key pressed
                       };

//#define COLUMN0     PORTBbits.RB1
//#define COLUMN1     PORTBbits.RB2
//#define COLUMN2     PORTBbits.RB3
//#define COLUMN3     PORTBbits.RB4
//
//#define ROW0        PORTBbits.RB5
//#define ROW1        PORTBbits.RB6
//#define ROW2        PORTBbits.RB7




void Keypad_Init(void);
unsigned char Keypad_Scan(void);                    
unsigned char Get_Key(void); 

#endif
