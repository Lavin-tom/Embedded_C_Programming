/*i2c_frames_eeprom.c*/
#include "header.h"
void i2c_byte_write_frame_eeprom(u8 sa,u8 mr,u8 d)
{
	bit ret;
	i2c_start_eeprom();
	//slave address with write option
	i2c_write_eeprom(sa);
	ret=i2c_ack_eeprom();
	if(ret==1)
				goto out;
	//master memory address
	i2c_write_eeprom(mr);
	ret=i2c_ack_eeprom();
	if(ret==1)
				goto out;
	//data 
	i2c_write_eeprom(d);
	ret=i2c_ack_eeprom();
	if(ret==1)
				goto out;
 out:
				i2c_stop_eeprom();
}

u8 i2c_byte_read_frame_eeprom(u8 sa,u8 mr)
{
	u8 temp;
	bit ret;
	i2c_start_eeprom();
	i2c_write_eeprom(sa); 	//SA+write
	ret=i2c_ack_eeprom();
	if(ret==1)
			goto out;
	
	i2c_write_eeprom(mr);
	ret=i2c_ack_eeprom();
	if(ret==1)
			goto out;
	
	i2c_start_eeprom(); 		//restart condion
	i2c_write_eeprom(sa|1);	//SA+Read
	ret=i2c_ack_eeprom();
	if(ret==1)
			goto out;
	
	temp=i2c_read_eeprom();
	i2c_noack_eeprom();	//optional
	out: 
		i2c_stop_eeprom();
		return temp;
}