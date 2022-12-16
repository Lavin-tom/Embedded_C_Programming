//2X3 keypad matrix driver.c
#include <reg51.h>
#include "my_header.h"

//pin declaration
sbit R0=P3^0;
sbit R1=P3^1;
sbit C0=P3^4;
sbit C1=P3^5;
sbit C2=P3^6;

//2x3 keypad matrix lookup table declaraion
u8 kpd_tbl[2][3]={1,2,3,
									4,5,6};
u8 keyscan(void){
	u8 row_num,col_num;

	R0=R1=0;
	C0=C1=C2=1;
	while((C0&C1&C2)==1);		//waiting for switch prese
	delay_ms(20);						//to avoid key debouncing
	//check for row 0
	R0=0;
	R1=1;
	if((C0&C1&C2)==0){
		row_num=0;
		goto colcheck;
	}
	//check for row 1
	R0=1;
	R1=0;
	if((C0&C1&C2)==0){
		row_num=1;
		goto colcheck;
	}
	//checking col no
	colcheck:
	if(C0==0)
		col_num=0;
	else if(C1==0)
		col_num=1;
	else
		col_num=2;
	while((C0&C1&C2)==0);			//wait for switch release
	return (kpd_tbl[row_num][col_num]);
}