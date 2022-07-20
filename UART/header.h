/*header.h*/

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u16;
typedef signed int s16;
typedef unsigned long int u32;
typedef signed long int s32;
typedef float f32;

extern void uart_init(u16 baud);
extern void uart_tx(u8 d);
