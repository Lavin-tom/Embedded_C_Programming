//write an ECP for displaying 4 digits number on 4 multiplexed connection of common anode segments
#include<reg51.h>
#include"delay.h"
sbit ca1=P3^0;
sbit ca2=P3^1;
sbit ca3=P3^2;
sbit ca4=P3^3;
#define SEG_CAT P2
void delay_ms(unsigned int Tdly_ms);
void disp_int_mux_CA_segs(int);
char code a[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
main()
{
	int i=1234,j;
	for(j=1000;j>0;j--)
		disp_int_mux_CA_segs(i);
	while(1);
}
void disp_int_mux_CA_segs(int num)
{
	//extracting the integer one by one
	//due to the limitation of active low and active high led we use not gate
	SEG_CAT=a[num/1000];
	ca1=0;//only left most seg selected for display
	delay_ms(2);
	ca1=1;
	SEG_CAT=a[(num/100)%10];
	ca2=0;
	delay_ms(2);
	ca2=1;
	SEG_CAT=a[(num/10)%10];
	ca3=0;
	delay_ms(2);
	ca3=1;
	SEG_CAT=a[num%10];
	ca4=0;
	delay_ms(2);
	ca4=1;//NOT gate is connected between CA terminal and portpin
}