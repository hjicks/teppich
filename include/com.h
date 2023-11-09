#pragma once
#include <u.h>

void com_init(uint16 port, uint32 baud_rate);
void com_putchar(uint16 port, uint8 c);
uint8 com_getchar(uint16 port);
void com1_putchar(char c);
void com1_puts(char* s);