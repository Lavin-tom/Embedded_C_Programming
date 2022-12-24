#ifndef __I2C_H
#define __I2C_H

#define _XTAL_FREQ          20000000 
#define I2C_CLOCK           100000
#define SSPADD_VAL  ((_XTAL_FREQ/(4*I2C_CLOCK))-1)

void I2C_Init(void);
void I2C_DeviceReady(unsigned char DevAddr);
void I2C_Byte_Write(unsigned char DevAddr,unsigned char RegAddr,unsigned char data);
unsigned char I2C_Byte_Read (unsigned char DevAddr,unsigned char RegAddr);
void I2C_Page_Write(unsigned char DevAddr,unsigned char RegAddr, unsigned char *buffer, unsigned char no_bytes);
void I2C_Page_Read(unsigned char DevAddr,unsigned char RegAddr, unsigned char *data, unsigned char no_bytes);


#endif
