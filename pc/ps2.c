#include <u.h>
#include <x86.h>
#include <ps2.h>
static char keymap[2][128] = 
{
	{
		"\0\x1b""1234567890-=\b\t"
		"qwertyuiop[]\r\0as"
		"dfghjkl;'`\0\\zxcv"
		"bnm,./\0*\0 \0\0\0\0\0\0"
		"\0\0\0\0\0\0\0""789-456+1"
		"230."
	},
	{
		"\0\x1b""!@#$%^&*()_+\b\t"
		"QWERTYUIOP{}\r\0AS"
		"DFGHJKL:\"~\0|ZXCV"
		"BNM<>?\0\0\0 \0\0\0\0\0\0"
		"\0\0\0\0\0\0\0""789-456+1"
		"230."
	},
};

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
