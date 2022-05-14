/*io_driver.c*/
#include<reg51.h>
#include"header.h"
void io_bit_write(u8 port_num,u8 pin_num,u8 val)
{
	switch(port_num)
	{
		case 0: /*port0*/
			if(val==1)
				P0 |=(1<<pin_num);
			else
				P0 &=~(1<<pin_num);
				break;
		case 1: /*port1*/
			if(val==1)
				P1 |=(1<<pin_num);
			else
				P1 &=~(1<<pin_num);
				break;
		case 2: /*port2*/
			if(val==1)
				P2 |=(1<<pin_num);
			else
				P2 &=~(1<<pin_num);
				break;
		case 3: /*port3*/
			if(val==1)
				P3 |=(1<<pin_num);
			else
				P3 &=~(1<<pin_num);
				break;
	}
}
/*This funciton is used to read live status of given IO pins*/
bit io_bit_read(u8 port_num,u8 pin_num)
{
	u8 stat;
	switch(port_num)
	{
		case PORT0:
			stat=((P0>>pin_num)&1)?1:0;
			break;
		case PORT1:
			stat=((P1>>pin_num)&1)?1:0;
			break;
		case PORT2:
			stat=((P2>>pin_num)&1)?1:0;
			break;
		case PORT3:
			stat=((P3>>pin_num)&1)?1:0;
			break;
	}
	return stat;
}