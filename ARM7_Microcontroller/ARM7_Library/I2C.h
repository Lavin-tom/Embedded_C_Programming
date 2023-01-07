#ifndef I2C_H
#define I2C_H

void I2C_Init(void);
void Send_Start(void);
void Send_Stop(void);
void I2C_Byte_Write(unsigned char device,unsigned char address,unsigned char data);

unsigned char I2C_Byte_Read(unsigned char device,unsigned char address);

void I2C_32K_Byte_Write(unsigned char device, unsigned int address,unsigned char data);

unsigned char I2C_32K_Byte_Read(unsigned char device, unsigned int address);

#endif
