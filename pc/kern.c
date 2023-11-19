#include <u.h>
#include <libc.h>
#include <mem.h>
#include <cons.h>
#include <pccons.h>


/* abandon hope, all ye who enter here */
void
panic(void)
{
	conswrite(pccons, "panic: give up. it's over.\n");
}

int
run(char* cmd)
{
	/* replace it with a proper table */
	if(!strcmp(cmd, "clear"))
	{
		consclear(pccons, ' ');
	}
	else if(!strcmp(cmd, "hello"))
	{
		conswrite(pccons, "hi");
	}
	else if(!strcmp(cmd, "reboot"))
		return 0;
	else
	{
		conswrite(pccons, "no such command");
	}

	conswrite(pccons, "\n");
	conswrite(pccons, "> ");
	return 1;

}

void
repl(void)
{
	char c;
	char *cmd;

	int i = 0;
	memset(cmd, 0, 16); 
	conswrite(pccons, "> ");
	while(1)
	{

		c = consread(pccons);

		consputc(pccons, c);

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

	consinit(pccons);
	//conswrite(pccons, "Teppich\n");
	vga_puts("Teppich\n");

	repl();
}
