//write an ECP for displaying 4 digits number on 4 multiplexed connection of common anode segments
#include<reg51.h>
#include"delay.h"
sbit ca1=P3^0;
sbit ca2=P3^1;
sbit ca3=P3^2;
sbit ca4=P3^3;
sbit ca5=P2^4;
#define SEG_CAT P2
void delay_ms(unsigned int Tdly_ms);
void disp_int_mux_CA_segs(int);
char code a[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
main()
{
	int i=1234,j;
	int k=0;
	for(j=1000;j>0;j--)
		disp_int_mux_CA_segs(i);
	while(1);
}
void disp_int_mux_CA_segs(int num)
{
	
	//extracting the integer one by one
	//due to the limitation of active low and active high led we use not gate
	int s2,s1,m2,m1,z=0;
	int k,counts2=0;
	/*int k=num;
	ca5=0;
	for(s2=0;s2<=9;s2++)
	{
	SEG_CAT=a[s2];
		ca4=0;
		delay_ms(100);
		ca4=1;
	}
	for(s1=0;s1<=5;s1++)
	{
	SEG_CAT=a[s1];
		ca3=0;
		delay_ms(100);
		ca3=1;
	}
	for(m2=0;m2<=9;m2++)
	{
	SEG_CAT=a[m2];
		ca2=0;
		delay_ms(100);
		ca2=1;
	}
	for(m1=0;m1<=5;m1++)
	{
	SEG_CAT=a[m1];
		ca1=0;
		delay_ms(100);
		ca1=1;
	}*/
	s2=0;
	s1=0;
	m2=0;
	m1=0;
for(;;)
{
//last segment
SEG_CAT=a[s2];
		if(s2==9)
			{
			s2=0;
			s1++;
			}
		s2++;
		ca4=0;
		delay_ms(10);
		ca4=1;
//second last segment		
SEG_CAT=a[s1];
		if(s1==6)			
		{
			s1=0;
			m2++;	
		}
		ca3=0;
		delay_ms(10);
		ca3=1;
//second segment			
SEG_CAT=a[m2];
		if(m2==9)
			{
				m2=0;
				m1++;
			}
			if(s1==6)
				{
					m2++;
				}
		ca2=0;
		delay_ms(10);
		ca2=1;			
//first segment	
SEG_CAT=a[m1];
		if(m1==6)			
		{
			m1=0;	
		}
		if(m2==9)
		{
			m1++;
		}
		ca1=0;
		delay_ms(10);
		ca1=1;
}
	
}