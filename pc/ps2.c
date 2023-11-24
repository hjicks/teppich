#include <u.h>
#include <x86.h>
#include <ps2.h>

uint8
ps2_read_status(void)
{
	return inb(KBC);
}

void
ps2_init()
{
	int a = 256 - 3; /* 11111100 */
	outb(KBC, SET_RATE);
	outb(KBC, a);
	/* kbstate = 0; */
}

char
ps2_getc()
{
	char c;
	int state;
	
	state = 0;
	while(1)
	{
		if(!(ps2_read_status() & 1))
			continue;

		c = inb(KBD);
		if(c & 0x80)
			continue;

		/* made shift */
		if((c == 0x2A) || (c == 0x36))
		{
			state = 1;
			continue;
		}
		return keymap[state][c];
	}
}
