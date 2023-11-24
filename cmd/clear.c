#include <u.h>
#include <libc.h>

#include <vga.h>
#include <ps2.h>

#include <err.h>

void
clear_usage(void)
{
	vga_puts("usage: clear [-k]\n");
}

int
clear_main(int argc, char **argv)
{

	char c;
	
	if(argc == 2)
	{
		if(!strcmp(argv[1], "-k"))
		{
			vga_puts("Please press any key to clear the screen\n");
			ps2_getc();
		}
		else 
		{
			clear_usage();
			return USAGE;
		}
	}
	
	vga_clear(c);
	return OK;
}
