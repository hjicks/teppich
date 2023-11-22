#include <u.h>
#include <libc.h>

#include <vga.h>
#include <bitmap.h>

void
echo_main(int argc, char **argv)
{
	int i;
	void (*puts)(char*);
	
	puts = vga_puts;
	i = 1;
	if(argc >= 1 && !strcmp(argv[1], "-b"))
	{
		puts = bitputs;
		i = 2;
	}
	
	while(i < argc)
	{
		puts(argv[i]);
		puts(" ");
		i++;
	}
	
	vga_putc('\n');
}
