//4x3 keypad matrix driver

#include <reg51.h>
#include "header.h"
//pin declarations//
sbit R0=P3^0;
sbit R1=P3^1;
sbit R2=P3^2;
sbit R3=P3^3;
sbit C0=P3^4;
sbit C1=P3^5;
sbit C2=P3^6;
sbit C3=P3^7;

//lookup table 2x3 keypad matrix//
u8 kpd_tbl[4][4]={49,50,51,8,
									52,53,54,10,
									55,56,57,48,
									42,48,35,13};
u8 keyscan(void)  
{
	u8 row_num,col_num;
	R0=R1=R2=R3=0;
	C0=C1=C2=C3=1;
	//waiting for switch press
	while((C0&C1&C2&C3)==1);
	//avoid key debouncing
	delay_ms(20);
	//checking row zero	
	R0=0;
	R1=1;
	R2=1;
	R3=1;
	if((C0&C1&C2&C3)==0)
	{
		row_num=0;
		goto colcheck;
	}
	//checking row one
	R0=1;
	R1=0;
	R2=1;
	R3=1;
	if((C0&C1&C2&C3)==0)
	{
		row_num=1;
		goto colcheck;
	}	
	//checking row two
	R0=1;
	R1=1;
	R2=0;
	R3=1;
	if((C0&C1&C2&C3)==0)
	{
		row_num=2;
		goto colcheck;
	}
	
	//checking row three
	R0=1;
	R1=1;
	R2=1;
	R3=0;
	if((C0&C1&C2&C3)==0)
	{
		row_num=3;
		goto colcheck;
	}	
	colcheck:
		if(C0==0)
			col_num=0;
		else if(C1==0)
			col_num=1;
		else if(C2==0)
			col_num=2;
		else if(C3==0)
			col_num=3;
		
	//waiting for switch release
	while((C0&C1&C2&C3)==0);
	return (kpd_tbl[row_num][col_num]);
}