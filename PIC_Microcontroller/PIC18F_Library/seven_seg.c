#include <xc.h>
#include "seven_seg.h"

// dp g f e d c b a  DA7-DA0

//EDCHGFAB
const char seg_data[]={ 0b11100111,         //0
                        0b00100001,         //1
                        0b11001011,         //2
                        0b01101011,         //3    
                        0b00101101,         //4
                        0b01101110,         //5
                        0b11101100,         //6
                        0b00100011,         //7
                        0b11101111,         //8
                        0b00101111};        //9    
//                               
//                               
//const char seg_data[]={0b11000000,0b11111001,0b10100100,0b10110000,0b10011001,
//                                 0b10010010,0b10000010,0b11111000,0b10000000,0b10010000};                               


//const char seg_data[]={0b11100111, 0b00000011, 0b11011001,0b01101011,0b10011001,
//                                 0b10010010,0b10000010,0b11111000,0b10000000,0b10010000};                               


unsigned char seg[4];

/*
void Seg_Init()     // For active High Logic
{
unsigned char i;
SEG7_TRIS=0x00;
SEG7_PORT=0x00;
EN0_TRIS=0;
EN1_TRIS=0;
EN2_TRIS=0;
EN3_TRIS=0;
ENABLE0=0;
ENABLE1=0;
ENABLE2=0;
ENABLE3=0;	
 for(i=0;i<4;i++)
  seg[i]=0;
}*/	

void Seg_Init()
{
    unsigned char i;
    SEG7_TRIS=0x00;
    SEG7_PORT=0xFF;
    EN0_TRIS=0;
    EN1_TRIS=0;
    EN2_TRIS=0;
    EN3_TRIS=0;
    ENABLE0=1;
    ENABLE1=1;
    ENABLE2=1;
    ENABLE3=1;	
     for(i=0;i<4;i++)
      seg[i]=255;
}


void Put_7Seg(unsigned int val)
{
    unsigned char dgt;	
    dgt=val%10;
    seg[0]=seg_data[dgt];
    val=val/10;

    dgt=val%10;
    seg[1]=seg_data[dgt];
    val=val/10;

    dgt=val%10;
    seg[2]=seg_data[dgt];
    val=val/10;

    dgt=val%10;
    seg[3]=seg_data[dgt];
    val=val/10;
 	
}


void SegMultiplex()            // For active High Logic
{
static unsigned char i=0;	

SEG7_PORT=0;

 if(i==0)
 {
  ENABLE0=1;
  ENABLE1=0;
  ENABLE2=0;
  ENABLE3=0;
 } 
 else if(i==1)
 {
  ENABLE0=0;
  ENABLE1=1;
  ENABLE2=0;
  ENABLE3=0;	 
 } 
 else if(i==2)
 {
  ENABLE0=0;
  ENABLE1=0;
  ENABLE2=1;
  ENABLE3=0;	 
 } 
 else
 {
  ENABLE0=0;
  ENABLE1=0;
  ENABLE2=0;
  ENABLE3=1;	 
 } 
 
SEG7_PORT=seg[i];    
  
i++;
 if(i==4)
  i=0;	
}		


//void SegMultiplex()
//{
//    static unsigned char i=0;       
//    SEG7_PORT=255;
//
//    if(i==0)
//    {
//        ENABLE0=0;
//        ENABLE1=1;
//        ENABLE2=1;
//        ENABLE3=1;
//    } 
//    else if(i==1)
//    {
//        ENABLE0=1;
//        ENABLE1=0;
//        ENABLE2=1;
//        ENABLE3=1;	 
//    } 
//    else if(i==2)
//    {
//        ENABLE0=1;
//        ENABLE1=1;
//        ENABLE2=0;
//        ENABLE3=1;	 
//    } 
//    else
//    {
//        ENABLE0=1;
//        ENABLE1=1;
//        ENABLE2=1;
//        ENABLE3=0;	 
//    } 
//    SEG7_PORT=seg[i];    
//    i++;
//    if(i==4)    i=0;	
//}	
