//write ECP for displaying the binary equalent of keyvalue on the LEDs
/*	sw1 sw2 sw3 sw4
		sw5 sw6 sw7 sw8
		sw9 sw10 sw11 sw12
		sw13 sw14 sw15 sw16*/
		
		#include<reg51.h>
		#include"leds_8.h"
		sbit r0=P2^0;
		sbit r1=P2^1;
		sbit r2=P2^2;
		sbit r3=P2^3;
		sbit c0=P2^4;
		sbit c1=P2^5;
		sbit c2=P2^6;
		sbit c3=P2^7;
		
		char code a[4][4]={1,2,3,4,
											5,6,7,8,
											9,10,11,12,
											13,14,15,16};
		main()
				{
					char row_num,col_num;
					while(1)
					{
						//row initialized as 0 P1=0xfo 1111 0000
						r0=0;
						r1=0;
						r2=0;
						r3=0;
						
						//wait until all cols status are high
						while(c0 && c1 && c2 && c3);
						
						//when one switch is pressed. status become low. come out of loop
						r0=0;
						r1=1;
						r2=1;
						r3=1;
						
						//if one of the column become low
						if(!(c0 && c1 && c2 && c3))
						{
							row_num=0;
							goto col_check;
						}
						r0=1;
						r1=0;
						r2=1;
						r3=1;
						
						//if one of the column become low
						if(!(c0 && c1 && c2 && c3))
						{
							row_num=1;
							goto col_check;
						}
						r0=1;
						r1=1;
						r2=0;
						r3=1;
						
						//if one of the column become low
						if(!(c0 && c1 && c2 && c3))
						{
							row_num=2;
							goto col_check;
						}
						r0=1;
						r1=1;
						r2=1;
						r3=0;
						
						//if one of the column become low
						if(!(c0 && c1 && c2 && c3))
						{
							row_num=3;
							goto col_check;
						}
						col_check:
										if(c0==0)
													col_num=0;
										else if(c1==0)
													col_num=1;
										else if(c2==0)
													col_num=2;
										else
													col_num=3;
							
						disp_bin_LEDs(a[row_num][col_num]);
										
										//waiting for switch release
										while(!(c0 && c1 && c2 && c3));
									}
				}