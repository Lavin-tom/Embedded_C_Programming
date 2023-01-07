
#include <LPC214x.h>
#include "I2C.h"

void I2C_Init(void)
{ 
	PINSEL0 = (PINSEL0 & 0xFFFFFF0F) | 0x00000050;	  //Configure Port pin as I2C pin
	I2C0CONCLR=0xFF;							   	//Clear All bits
	I2C0CONSET=0x40;								//Set I2C Enable
	I2C0SCLH=75;									//Set I2C_Clock = 100Khz
	I2C0SCLL=75;									//with 50% duty cycle
}

void Send_Start(void)
{
 	I2C0CONSET=0x20; 
}


void Send_Stop(void)
{
 	I2C0CONSET=0x10;
}


void I2C_Byte_Write(unsigned char device,unsigned char address,unsigned char data)
{
	
	I2C0CONCLR=0xFF;				//Clear All bits
	I2C0CONSET=0x40;			   	//Set I2C Enable	
	
	Send_Start();					 //Send Start Condition
	while(!(I2C0CONSET&0x08));		 //Check SI Flag
	I2C0CONCLR=0x28;				//Clear SI flag
	
	I2C0DAT= device&0xFE;			 //Selecting device in write mode
	while(!(I2C0CONSET& 0x08)); 	//Check SI Flag
	I2C0CONCLR=0x28;				//Clear SI flag
	
	I2C0DAT= address;  				//Sending Memory Location
	while(!(I2C0CONSET& 0x08)); 	//Check SI Flag
	I2C0CONCLR=0x28;				//Clear SI flag
	
	I2C0DAT= data;				 	//Sending data
	while(!(I2C0CONSET& 0x08)); 	//Check SI Flag
  	I2C0CONCLR=0x28;	
	
	Send_Stop();					//send stop condition	
}


unsigned char I2C_Byte_Read(unsigned char device,unsigned char address)
{
	unsigned char data;

	I2C0CONCLR=0xFF;	//Clear All bits
	I2C0CONSET=0x40;	//Set I2C Enable	
	
	Send_Start();			//Send Start Condition
	while(!(I2C0CONSET& 0x08)); //Check SI Flag
	I2C0CONCLR=0x28;	//Clear SI flag
	
	I2C0DAT= device&0xFE; //Selecting device in write mode
	while(!(I2C0CONSET& 0x08)); //Check SI Flag
	I2C0CONCLR=0x28;	//Clear SI flag
	
	I2C0DAT= address;		//Sending Memory Location
	while(!(I2C0CONSET& 0x08)); //Check SI Flag
	I2C0CONCLR=0x28;	//Clear SI flag
	
	Send_Start();		   // Repeat Start
	while(!(I2C0CONSET& 0x08)); //Check SI Flag
	I2C0CONCLR=0x28;	//Clear SI flag
	
	I2C0DAT= device | 0x01;	//Selecting device in read mode
	while(!(I2C0CONSET& 0x08)); //Check SI Flag
	I2C0CONCLR=0x28;	//Clear SI flag
	I2C0CONCLR=0x04;		 //set hardware to send nack
	
	while(!(I2C0CONSET& 0x08)); //Check SI Flag
	I2C0CONCLR=0x28;	//Clear SI flag
	data=I2C0DAT;	
	
	Send_Stop();		//send stop condition
	return data;
}


void I2C_32K_Byte_Write(unsigned char device, unsigned int address,unsigned char data)
{
	volatile unsigned char AddrHiByte, AddrLoByte;
    
	AddrHiByte  = (unsigned char)((address  & 0xFF00) >> 8); 
	AddrLoByte  = (unsigned char)(address & 0x00FF);
	
	
	I2C0CONCLR=0xFF;	//Clear All bits
	I2C0CONSET=0x40;	//Set I2C Enable	
	
	Send_Start();				//Send Start Condition
	while(!(I2C0CONSET&0x08)); 	//Check SI Flag
	I2C0CONCLR=0x28;			//Clear SI flag
	
	I2C0DAT= device&0xFE; 		//Selecting device in write mode
	while(!(I2C0CONSET& 0x08)); //Check SI Flag
	I2C0CONCLR=0x28;			//Clear SI flag
	
	I2C0DAT= AddrHiByte;  			//Sending Memory Location
	while(!(I2C0CONSET& 0x08)); //Check SI Flag
	I2C0CONCLR=0x28;			//Clear SI flag

	I2C0DAT= AddrLoByte;  			//Sending Memory Location
	while(!(I2C0CONSET& 0x08)); //Check SI Flag
	I2C0CONCLR=0x28;			//Clear SI flag
	
	I2C0DAT= data;				//Sending data
	while(!(I2C0CONSET& 0x08)); //Check SI Flag
  	I2C0CONCLR=0x28;	
	
	Send_Stop();		//send stop condition
	
}


unsigned char I2C_32K_Byte_Read(unsigned char device, unsigned int address)
{
	unsigned char data;
	volatile unsigned char AddrHiByte, AddrLoByte;
    
	AddrHiByte  = (unsigned char)((address  & 0xFF00) >> 8); 
	AddrLoByte  = (unsigned char)(address & 0x00FF);


	I2C0CONCLR=0xFF;	//Clear All bits
	I2C0CONSET=0x40;	//Set I2C Enable	
	
	Send_Start();			//Send Start Condition
	while(!(I2C0CONSET& 0x08)); //Check SI Flag
	I2C0CONCLR=0x28;	//Clear SI flag
	
	I2C0DAT= device&0xFE; //Selecting device in write mode
	while(!(I2C0CONSET& 0x08)); //Check SI Flag
	I2C0CONCLR=0x28;	//Clear SI flag
	
	I2C0DAT= AddrHiByte;		//Sending Memory Location
	while(!(I2C0CONSET& 0x08)); //Check SI Flag
	I2C0CONCLR=0x28;	//Clear SI flag

	I2C0DAT= AddrLoByte;		//Sending Memory Location
	while(!(I2C0CONSET& 0x08)); //Check SI Flag
	I2C0CONCLR=0x28;	//Clear SI flag
	
	Send_Start();		   // Repeat Start
	while(!(I2C0CONSET& 0x08)); //Check SI Flag
	I2C0CONCLR=0x28;	//Clear SI flag
	
	I2C0DAT= device | 0x01;	//Selecting device in read mode
	while(!(I2C0CONSET& 0x08)); //Check SI Flag
	I2C0CONCLR=0x28;	//Clear SI flag
	I2C0CONCLR=0x04;		 //set hardware to send back
	
	while(!(I2C0CONSET& 0x08)); //Check SI Flag
	I2C0CONCLR=0x28;	//Clear SI flag
	data=I2C0DAT;	
	
	Send_Stop();		//send stop condition
	return data;
}
