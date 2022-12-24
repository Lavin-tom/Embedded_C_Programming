#ifndef __UART_H
#define __UART_H

void UART_Init (void);
void TransmitByte (unsigned char TXbyte);
unsigned char ReceiveByte (void);
void TransmitString (unsigned char *ptr);

#endif
