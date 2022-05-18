//lcd main.c//

#include "header.h"
#include<string.h>
main()
{
	u8 temp,i=0,j,pwd[4],op,default_pwd[4]={49,50,51,52};
	lcd_init();
	lcd_string("Enter Passcode");
	lcd_cmd(0xc0);
	while(1)
	{
	temp=keyscan();
	if(temp==8)
		{
		//cmd for backspace
		lcd_cmd(0x04);
			i--;
		}
		//lcd_data(temp);	
		
		//cmd for increment the curson after shifting the cursor to left    
		lcd_cmd(0x06);
		if(temp==13)
			{
			//pwd[i]='\0';
			lcd_cmd(0x1);
			lcd_cmd(0xc);
			//lcd_string(pwd);
			lcd_string("CHECKING..");
			delay_ms(1000);
			lcd_cmd(0x80);	
				
			
			//pwd authentication
			/*lcd_cmd(0x1);
			lcd_data(pwd[0]);
			lcd_data(default_pwd[0]);
			lcd_data(pwd[1]);
			lcd_data(default_pwd[1]);	
			lcd_data(pwd[2]);
			lcd_data(default_pwd[2]);	
			lcd_data(pwd[3]);
			lcd_data(default_pwd[3]);	
			delay_ms(10000);*/
				
			for(j=0;j<4;j++)
			{
			if(pwd[j]!=default_pwd[j])
				break;
			}
			
			if(j==4)
			{
				lcd_cmd(0x1);
				lcd_string("PASSCODE"); 
				lcd_cmd(0xc0);
				lcd_string("IS RIGHT");
				delay_ms(1000);
				lcd_cmd(0x1);
				lcd_string("WELCOME");
				delay_ms(1000);
				lcd_cmd(0x1);
				option(temp,op);
			}
			else
			{
				lcd_cmd(0x1);
				lcd_string("PASSCODE"); 
				lcd_cmd(0xc0);
				lcd_string("IS WRONG");
				delay_ms(500);
				lcd_cmd(0x1);
				lcd_string("TRY AGAIN");
				delay_ms(500);
				lcd_cmd(0x1);
				i=0;
				lcd_string("Enter Passcode");
				lcd_cmd(0xc0);
				
			}
			}
			//entered data into array when not press backspace and enter
		if(temp!=13 && temp!=8)
			{
				pwd[i]=temp;
				//show star instend of actual integer
				lcd_data(42);
				i++;
			}
			
	}
}
//option start
			void option(int temp,int op)
			{
				lcd_string("1.CHANGE PASSWORD");
				if(temp==13)
				{
				op=temp;
				lcd_data(op);
				}
			}