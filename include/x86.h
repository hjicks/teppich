#pragma once
#include <u.h>

#define COM1 0x3F8

#define KBD 0x60
#define KBC 0x64

#define VGAC 0x3d4
#define VGAD 0x3d5

#define outb(port,data) asm volatile("out %0, %1" : : "a" (data), "d" (port));

#define inb(port) ({ \
unsigned char _v; \
__asm__ volatile ("inb %%dx,%%al":"=a" (_v):"d" (port)); \
_v; \
})

void instr(uint16 port, uint8* address, uint32 size);
void sti(void);
void cli(void);
void nop(void);
