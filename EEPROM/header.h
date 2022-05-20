/*header.h*/

#define PORT0 0
#define PORT1 1
#define PORT2 2
#define PORT3 3

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u16;
typedef signed int s16;
typedef unsigned long int u32;
typedef signed long int s32;
typedef float f32;

extern void delay_ms(u16 ms);
extern void lcd_data(u8 d);
extern void lcd_cmd(u8 c);
extern void lcd_init(void);
extern void lcd_string(s8 *ptr);

extern u8 keyscan(void);

extern void i2c_start(void);
extern void i2c_stop(void);
extern void i2c_write(u8 d);
extern u8 i2c_read(void);
extern bit i2c_ack(void);
extern void i2c_noack(void);

extern void i2c_byte_write_frame(u8 sa,u8 mr,u8 d);
extern u8 i2c_byte_read_frame(u8 sa,u8 mr);