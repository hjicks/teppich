#include <u.h>
#include <x86.h>
#include <ps2.h>

uint8
ps2_read_status(void)
{
	return inb(KB_CTR);
}

void
ps2_init()
{
	int a = 256 - 3; // 11111100
	outb(0x64, SET_RATE);
	outb(0x64, a);
}

char
ps2_getc()
{
	char c;
	if(!(ps2_read_status() & 1))
		return 0;

	c = inb(KB);
	if(c & 0x80)
		return 0;

	return keymap[c];
}
