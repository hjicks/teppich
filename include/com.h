#pragma once
#include <u.h>

void com_init(uint16 port, uint32 baud_rate);
void com_putchar(uint16 port, uint8 c);
void com_putc(char c);
void com_puts(char* s);
char com_getchar(uint16 port);
char com_getc(void);
char* com_getl(void);