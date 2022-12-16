//io_driver.c
#include <reg51.h>
#include "my_header.h"
void io_bit_write(u8 port_num,u8 pin_num,
									u8 val){
								
		switch(port_num){
				case 0:
							if(val==1)
								P0|=(1<<pin_num);
							else
								P0&=~(1<<pin_num);
							break;
				case 1:
							if(val==1)
								P1|=(1<<pin_num);
							else
								P1&=~(1<<pin_num);
							break;
				case 2:
							if(val==1)
								P2|=(1<<pin_num);
							else
								P2&=~(1<<pin_num);
							break;
				case 3:
							if(val==1)
								P3|=(1<<pin_num);
							else
								P3&=~(1<<pin_num);
							break;
						}
					}
		void io_byte_write(u8 port_num,u8 byte)
		{
				switch (port_num)
				{
					case 0:
							P0 = byte;
							break;
					case 1:
							P1 = byte;
							break;
					case 2:
							P2 = byte;
							break;
					case 3:
							P3 = byte;
							break;
				}
		}
		bit io_bit_read(u8 port_num,u8 pin_num)
		{
			u8 stat;
			switch(port_num)
			{
				case 0:
					stat=((P0>>pin_num)&1)?1:0;
					break;
				case 1:
					stat=((P1>>pin_num)&1)?1:0;
					break;
				case 2:
					stat=((P2>>pin_num)&1)?1:0;
					break;
				case 3:
					stat=((P3>>pin_num)&1)?1:0;
					break;
			}
			return stat;
		}