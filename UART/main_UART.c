//write an ECP for receiving a character through UART
//and if it is lower case convert it into upper or viceversa 
//and transmit the character back through UART using 
//8 data bits,1 stop bit, no parity with 9600 braud rate

//solution
//select m1 with reception enabled
//braudrate= (2^smod*fosc)/(12*32*(256-TH1))
//9600=(2^0*11.0592mhz)/(12*32*(256-TH1)
//9600=28800/(256-TH1)
//TH1 256-3=253 or -3
//scon reg
//SM0 SM1 SM2 REN TB8 RB8 T1 R1
//0		1		0		1			0	 0	0	 0

#include<reg51.h>
void Init_UART(void);
char Rx_char_UART(void);
void Tx_char_UART(char);
main()
{
	char ch;
	Init_UART();
	while(1)
	{
		//receiver function call
		ch=Rx_char_UART();
		if(ch>='a' && ch<='z')
			ch=ch-32;			//convert to upper case
		else if(ch>='A' && ch<='Z')
			ch=ch+32;			//convert to lower case
		else
		{
			//if any other characters enter do nothing
		}
		Tx_char_UART(ch);
	}
}

//initializaiton of uart
void Init_UART(void)
{
	SCON=0x50;	//select M! with reception enabled
	TMOD=0x20; 	//timer 1 mode 2
	TH1=253;		//9600 @ fosc=11.0592Mhz
	TR1=1;			//T1 in running mode
}

//receiver
char Rx_char_UART(void)
{
	while(R1==0);			//waiting for the data receive
	R1=0;
	return(SBUF);
}

//transmission
char Tx_char_UART(char dat)
{
	SBUF=dat;				//load the value into sbuf
	while(TI==0);		//wait for transmission complete
	TI=0;
}
