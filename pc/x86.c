#include <u.h>

void
outb(uint16 port, uint8 data)
{ 
	asm volatile("out %0, %1" : : "a" (data), "d" (port));
}

uint8
inb(uint16 port)
{
	uint8 data;
	asm volatile("in %1, %0" : "=a" (data) : "d" (port)); 
	return data;
}
