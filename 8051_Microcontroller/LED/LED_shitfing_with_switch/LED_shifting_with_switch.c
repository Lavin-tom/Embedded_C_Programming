//LED shifting with switch
#include "my_header.h"
#include <reg51.h>
main(){
	u8 ltemp=1,count=0,rtemp=8;
	while(1)
	{
			//while(io_bit_read(PORT3,0)==0 || io_bit_read(PORT3,1)==0);
			if(io_bit_read(PORT3,0)==0)
			{
				io_byte_write(PORT2,~rtemp);
				rtemp=rtemp/2;
			}
			if(io_bit_read(PORT3,1)==0)
			{
				io_byte_write(PORT2,~ltemp);
				ltemp=ltemp*2;
			}
			count++;
			delay_ms(100);
			if(count==4){
				ltemp=1;
				rtemp=8;
				count=0;
			}
			 io_byte_write(PORT2,1);
	}
}