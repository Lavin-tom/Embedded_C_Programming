#include <xc.h>
#include "I2C.h"

//i2c initialization
void I2C_Init()
{
    TRISCbits.TRISC3=1;       //Setting up SDA/SCL pins as inputs
    TRISCbits.TRISC4=1;	

    //SSPCON1 = 0x08;		//I2C Master mode, clock = FOSC/(4 * (SSPADD + 1))

    SSPCON1bits.SSPM3=1;      //I2C Master mode, clock = FOSC/(4 * (SSPADD + 1))
    SSPCON1bits.SSPM2=0;
    SSPCON1bits.SSPM1=0;
    SSPCON1bits.SSPM0=0;	

    //SSPCON1bits.CKP=0;        //Unused in master mode

    //SSPSTATbits.SMP=1;        //Enabling slew control for high sped mode
    //SSPSTATbits.CKE=0;        //Disable SMBus specific inputs	
    //SSPADD= SSPADD_VAL;        //Setting I2C clock
    SSPADD = 49;
    SSPCON1bits.SSPEN=1;      //Enabling MSSP module
}	


void I2C_DeviceReady(unsigned char DevAddr)
{
    SSPCON2bits.SEN=1;           //Generating start condition
    while(!PIR1bits.SSPIF);      //Waiting for transmission of start bit
    PIR1bits.SSPIF=0;            //Clearing SSPIF flag
    while(1)
    {
        SSPBUF= DevAddr&0xFE;       //Sending Address with write operation
        while(!PIR1bits.SSPIF);     //Waiting for transmission of address along with reception of ACK bit
        PIR1bits.SSPIF=0;            //Clearing SSPIF flag 
        if(SSPCON2bits.ACKSTAT==1)   //Checking if salve is ready rechecking if not
        {
            SSPCON2bits.RSEN=1;
            while(!PIR1bits.SSPIF);
            PIR1bits.SSPIF=0;	 
        }
        else
        {
            SSPCON2bits.PEN=1;
            while(!PIR1bits.SSPIF);
            PIR1bits.SSPIF=0;	 
            break; 
        } 
    }	
}	

//i2c for byte write
void I2C_Byte_Write(unsigned char DevAddr, unsigned char RegAddr,unsigned char data)
{
    SSPCON2bits.SEN=1;           //Generating start condition
    while(!PIR1bits.SSPIF);      //Waiting for transmission of start bit
    PIR1bits.SSPIF=0;            //Clearing SSPIF flag

    SSPBUF = DevAddr&0xFE;        //Sending Device Address with write operation
    while(!PIR1bits.SSPIF);      //Waiting for transmission of device address
    PIR1bits.SSPIF=0;            //Clearing SSPIF flag 

    SSPBUF = RegAddr;			 //Sending Register / Memory Location
    while(!PIR1bits.SSPIF);      //Waiting for transmission of memory address
    PIR1bits.SSPIF=0;            //Clearing SSPIF flag 

    SSPBUF = data;
    while(!PIR1bits.SSPIF);
    PIR1bits.SSPIF=0;  

    SSPCON2bits.PEN=1;        //Generating STOP condition
    while(!PIR1bits.SSPIF);   //Waiting for transmission of stop bit
    PIR1bits.SSPIF=0;         //Clearing SSPIF flag	     
}

//i2c byte read
unsigned char I2C_Byte_Read(unsigned char DevAddr,unsigned char RegAddr)
{
    unsigned char data;
    SSPCON2bits.SEN=1;           //Generating start condition
    while(!PIR1bits.SSPIF);      //Waiting for transmission of start bit
    PIR1bits.SSPIF=0;            //Clearing SSPIF flag

    SSPBUF = DevAddr & 0xFE;          //Selecting device in write mode
    while(!PIR1bits.SSPIF);      //Waiting for transmission of device address along with reception of ACK bit
    PIR1bits.SSPIF=0;            //Clearing SSPIF flag 

    SSPBUF = RegAddr;              //Setting read address
    while(!PIR1bits.SSPIF);
    PIR1bits.SSPIF=0;  

    SSPCON2bits.RSEN=1;          //generating repeated start condition
    while(!PIR1bits.SSPIF);
    PIR1bits.SSPIF=0;	  

    ////Sending Read Command
    SSPBUF = DevAddr|0x01;          //Sending Address
    while(!PIR1bits.SSPIF);      //Waiting for transmission of read command along with reception of ACK bit
    PIR1bits.SSPIF=0;            //Clearing SSPIF flag 

    SSPCON2bits.RCEN=1;          //Enabling Master Receive Mode
    while(!PIR1bits.SSPIF);      //Waiting to receive a byte
    PIR1bits.SSPIF=0;            //Clearing interrupt flag 	 
    
    data=SSPBUF;                //Getting received data byte  

    SSPCON2bits.PEN=1;           //Generating STOP condition
    while(!PIR1bits.SSPIF);
    PIR1bits.SSPIF=0;	 
    return data;
}

//i2c page write
void I2C_Page_Write(unsigned char DevAddr,unsigned char RegAddr,unsigned char *data,unsigned char no_bytes)
{
    unsigned char i;	
    SSPCON2bits.SEN=1;           //Generating start condition
    while(!PIR1bits.SSPIF);      //Waiting for transmission of start bit
    PIR1bits.SSPIF=0;            //Clearing SSPIF flag

    SSPBUF = DevAddr&0xFE;          //Sending Address
    while(!PIR1bits.SSPIF);      //Waiting for transmission of address along with reception of ACK bit
    PIR1bits.SSPIF=0;            //Clearing SSPIF flag 

    SSPBUF = RegAddr;
    while(!PIR1bits.SSPIF);
    PIR1bits.SSPIF=0;  

    for(i=0;i<no_bytes;i++)
    { 
        SSPBUF=data[i];
        while(!PIR1bits.SSPIF);
        PIR1bits.SSPIF=0;  
    } 
    SSPCON2bits.PEN=1;        //Generating STOP condition
    while(!PIR1bits.SSPIF);
    PIR1bits.SSPIF=0; 	
}		

//i2c page read
void I2C_Page_Read(unsigned char DevAddr,unsigned char RegAddr,unsigned char *data,unsigned char no_bytes)
{
    unsigned char i;
    SSPCON2bits.SEN=1;           //Generating start condition
    while(!PIR1bits.SSPIF);      //Waiting for transmission of start bit
    PIR1bits.SSPIF=0;            //Clearing SSPIF flag

    SSPBUF = DevAddr&0xFE;          //Selecting device in write mode
    while(!PIR1bits.SSPIF);      //Waiting for transmission of device address along with reception of ACK bit
    PIR1bits.SSPIF=0;            //Clearing SSPIF flag 

    SSPBUF = RegAddr;              //Setting read address
    while(!PIR1bits.SSPIF);
    PIR1bits.SSPIF=0;  

    SSPCON2bits.RSEN=1;          //generating repeated start condition
    while(!PIR1bits.SSPIF);
    PIR1bits.SSPIF=0;	  

    //Sending Read Command
    SSPBUF = DevAddr|0x01;          //Sending Address with read 
    while(!PIR1bits.SSPIF);      //Waiting for transmission of read command along with reception of ACK bit
    PIR1bits.SSPIF=0;            //Clearing SSPIF flag 

    /////// Master receiving configuration //////////
    for(i=0;i<(no_bytes-1);i++)
    { 
        SSPCON2bits.RCEN=1;          //Enabling Master Receive Mode
        while(!PIR1bits.SSPIF);      //Waiting to receive a byte
        PIR1bits.SSPIF=0;            //Clearing interrupt flag

        SSPCON2bits.ACKDT=0;         //Positively acknowledging reception of data
        SSPCON2bits.ACKEN=1;         //Starting acknowlegment procedure

        while(!PIR1bits.SSPIF);      //Waiting for acknowledgement transmission
        PIR1bits.SSPIF=0;   	 
        data[i]=SSPBUF;                //Getting received data byte 
    }

    SSPCON2bits.RCEN=1;          //Enabling Master Receive Mode
    while(!PIR1bits.SSPIF);      //Waiting to receive a byte
    PIR1bits.SSPIF=0;            //Clearing interrupt flag

    SSPCON2bits.ACKDT=1;         //Positively acknowledging reception of data
    SSPCON2bits.ACKEN=1;         //Starting acknowlegment procedure

    while(!PIR1bits.SSPIF);      //Waiting for neg_acknowledgement transmission
    PIR1bits.SSPIF=0;   	 
    data[i]=SSPBUF;              //Getting received data byte 

    SSPCON2bits.PEN=1;           //Generating STOP condition
    while(!PIR1bits.SSPIF);
    PIR1bits.SSPIF=0;	 
}
