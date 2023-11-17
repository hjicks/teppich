#include <u.h>
#include <vga.h>
#include <com.h>
#include <ps2.h>
#include <mem.h>
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
	{
		vga_puts("\nno such command\n");
	}

	vga_putc('\n');
	vga_puts("> ");
	return 1;

}

void
repl(void)
{
	char c;
	char *cmd;

	int i = 0;
	memset(cmd, 0, 16); 
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
			cmd = malloc(16);
			i = 0;
			
		}
		else if(c != '\b')
		{
			*(cmd+i) = c;
			i++;
		}
		else
		{
			/* we don't want a negative i */
			if(i)
				i--;
			*(cmd+i) = 0;
			
		}
	}
}

void
kernel_main(void) 
{
	memset(memap, FREE, MEM_MAX * (1024 / BLOCKSIZE));

	vga_init(BLUE, LIGHT_GREY);
	vga_puts("Teppich\n");

	repl();
}
