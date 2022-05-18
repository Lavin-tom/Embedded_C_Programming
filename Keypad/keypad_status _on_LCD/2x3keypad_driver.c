#include <reg51.h>
#include "header.h"
//pin declarations//
sbit R0=P3^0;
sbit R1=P3^1;
sbit C0=P3^4;
sbit C1=P3^5;
sbit C2=P3^6;

//lookup table 2x3 keypad matrix//

u8 kpd_tbl[2][3]={1,2,3,4,5,6};
u8 keyscan(void)  
{
	u8 row_num,col_num;
	R0=R1=0;
	C0=C1=C2=1;
	//waiting for switch press
	while((C0&C1&C2)==1);
	//avoid key debouncing
	delay_ms(20);
	//checking row zero	
	R0=0;
	R1=1;
	if((C0&C1&C2)==0)
	{
		row_num=0;
		goto colcheck;
	}
	//checking row one
	R0=1;
	R1=0;
	if((C0&C1&C2)==0)
	{
		row_num=1;
		goto colcheck;
	}	

	colcheck:
		if(C0==0)
			col_num=0;
		else if(C1==0)
			col_num=1;
		else if(C2==0)
			col_num=2;
	//waiting for switch release
	while((C0&C1&C2)==0);
	return (kpd_tbl[row_num][col_num]);
}