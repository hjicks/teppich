#include <vga.h>
#include <com.h>
#include <ps2.h>
#include <libc.h>

/* abandon hope, all ye who enter here */
void
panic(void)
{
	vga_puts("panic: give up. it's over.\n");
	com_puts("panic: give up. it's over.\n");
	
}

int
run(char* cmd)
{
	/* vga_puts(cmd); */

	/* replace it with a proper table */
	if(!strcmp(cmd, "clear"))
	{
		vga_clear(' ');
	}
	else if(!strcmp(cmd, "hello"))
	{
		vga_puts("hi");
	}
	else if(!strcmp(cmd, "reboot"))
		return 0;
	else
		vga_puts("no such command");

	vga_putc('\n');
	return 1;

}

void
repl(void)
{
	char c;
	char *cmd = "";
	int i = 0;

	vga_puts("salam az Teppich\n");
	vga_puts("> ");

	while(1)
	{

		c = ps2_getc();
		if(c == 0)
			continue;

		vga_putc(c);

		if(c == '\r' || c == '\n')
		{
			if(!run(cmd))
				return;
			/* clear the mess */
			i = 0;
			memset(cmd, 0, 16);

			vga_puts("> ");

		}
		else
		{
			*(cmd+i) = c; /* heb */
			i++;
		}
	}
}


void
kernel_main(void) 
{
	vga_init(WHITE, BLUE);

	repl();
}
