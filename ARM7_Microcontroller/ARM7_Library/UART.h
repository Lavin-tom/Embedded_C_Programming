//uart header file

#ifndef UART_H
#define UART_H

void UART_Init(void);
void UART_Transmit_Byte(unsigned char Data);
unsigned char UART_Receive(void);
void UART_Transmit_String(unsigned char *string);

#endif
