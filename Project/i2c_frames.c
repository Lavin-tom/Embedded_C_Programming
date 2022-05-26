/*i2c_frames.c*/
#include "header.h"
void i2c_write_frame(u8 sa,u8 mr,u8 d)
{
	bit ret;
	i2c_start();
	//slave address with write option
	i2c_write(sa);
	ret=i2c_ack();
	if(ret==1)
				goto out;
	//master memory address
	i2c_write(mr);
	ret=i2c_ack();
	if(ret==1)
				goto out;
	//data 
	i2c_write(d);
	ret=i2c_ack();
	if(ret==1)
				goto out;
 out:
				i2c_stop();
}

u8 i2c_read_frame(u8 sa,u8 mr)
{
	u8 temp;
	bit ret;
	i2c_start();
	i2c_write(sa); 	//SA+write
	ret=i2c_ack();
	if(ret==1)
			goto out;
	
	i2c_write(mr);
	ret=i2c_ack();
	if(ret==1)
			goto out;
	
	i2c_start(); 		//restart condion
	i2c_write(sa|1);	//SA+Read
	ret=i2c_ack();
	if(ret==1)
			goto out;
	
	temp=i2c_read();
	i2c_noack();	//optional
	out: 
		i2c_stop();
		return temp;
}