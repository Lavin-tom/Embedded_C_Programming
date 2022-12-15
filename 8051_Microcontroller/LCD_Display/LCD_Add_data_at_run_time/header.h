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
extern void io_bit_write(u8 port_num,u8 pin_num,u8 val);
extern bit io_bit_read(u8 port_num,u8 pin_num);
void lcd_data(u8 d);
void lcd_string(s8 *ptr);
void lcd_cmd(u8 c);
void lcd_init(void);