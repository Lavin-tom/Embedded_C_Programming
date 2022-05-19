//lcd main.c//

#include "header.h"
#include<string.h>
main()
{
	u8 temp,i=0,j,temp1,flag=0,pwd[4],op,default_pwd[4]={49,50,51,52};
	lcd_init();
	lcd_string("Enter Passcode");
	lcd_cmd(0xc0);
	while(1)
	{
	temp=keyscan();
		//option start
			if(temp==10 && flag==1)
			{
				i=0;
				lcd_string("1.PASSWORD CHANGE");
				while(1)
				{
				temp1=keyscan();
				//while(1)
				//{
				
				
				if(temp1!=13 && temp1!=8)
				{
				lcd_cmd(0xc0);	
				default_pwd[i]=temp1+48;
				
				//show star instend of actual integer
				lcd_data(temp1);
				//lcd_data(42);
				i++;
				}
				if(temp1==13)
				{
				lcd_cmd(0x1);
				lcd_string("PASSWORD");
				lcd_cmd(0xc0);
				lcd_string("UPDATED");
				delay_ms(500);
				lcd_cmd(0x1);
				break;
				}
				}
				/*if(temp1==13)
				{
				op=temp1;
				lcd_data(op);
				}*/
			}
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
			for(j=0;j<4;j++)
			{
			if(pwd[j]!=default_pwd[j])
				break;
			}
			
			if(j==4)
			{
				flag=1;
				lcd_cmd(0x1);
				lcd_string("PASSCODE"); 
				lcd_cmd(0xc0);
				lcd_string("IS RIGHT");
				delay_ms(1000);
				lcd_cmd(0x1);
				lcd_string("WELCOME");
				delay_ms(1000);
				lcd_cmd(0x1);
				//option(temp,op);
			}
			else
			{
				flag=0;
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