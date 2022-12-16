//my_header.h
#define PORT0 0
#define PORT1 1
#define PORT2 2
#define PORT3 3
#define LED_PIN_NUM 0
#define LCD_DATA P0


typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u16;
typedef signed int s16;
typedef unsigned long int u32;
typedef signed long int s32;
typedef float f32;

extern void io_bit_write(u8 port_num,
									u8 pin_num,
									u8 val);
extern void io_byte_write(u8 port_num,
									u8 byte);
extern bit io_bit_read(u8 port_num,u8 pin_num);

extern void delay_ms(u16 ms);
extern void lcd_data(u8 d);
extern void lcd_string(u8 *ptr);
extern void lcd_integer(s16 num);
extern void lcd_float(f32 num);
extern void lcd_cmd(u8 c);
extern void lcd_init(void);
extern u8 keyscan(void);