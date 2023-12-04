#pragma once
#include <u.h>

#define COM1 0x3F8

#define KBD 0x60
#define KBC 0x64

#define VGAC 0x3d4
#define VGAD 0x3d5

extern inline uint8 inb(uint16 port);
extern inline void outb(uint16 port, uint8 data);