//SPI.h

#ifndef SPI_H
#define SPI_H

#define SSEL0_DIR	IODIR0 |= 1 << 7  
#define SSEL0_SET	IOSET0 = 1 << 7
#define SSEL0_CLR	IOCLR0 = 1 << 7 


void SPI_Init(void);
unsigned char SPI_SendReceive(unsigned char Data);

#endif
