#include <u.h>
#include <libc.h>

#include <ps2.h>
#include <vga.h>

#include <mem.h>
#include <err.h>
#include "rc.h"

int
run(char *cmd)
{
	int argc;
	char *arg0, **argv;
	
	/* always always always
	check for nil pointers */
	
	arg0 = strcntok(cmd, ' ', 0);
	
	if(!arg0)
	{
		arg0 = cmd;
		argc = 0;
	}
	else
	{
		for(argc = 0 ; argc < (strccnt(cmd, ' ') + 1) ; argc++)
		{
			argv[argc] = strcntok(cmd, ' ', argc);
		}
	}
	for(int i = 0 ; i < sizeof(cmdtbl) ; i++)
	{
		if(!strcmp(arg0, cmdtbl[i].name))
			return cmdtbl[i].main(argc, argv);
	}
	vga_puts("No such command\n");
	
	return NO_SUCH_CMD;
}

void
rc_main(void)
{
	char c;
	char *cmd;

	int i = 0;
	memset(cmd, 0, 25);
	
	vga_puts("> ");
	while(1)
	{
		c = ps2_getc();
		vga_putc(c);
		
		if(c == '\r' || c == '\n')
		{
			cmd[i] = '\0';
			run(cmd);
			
			/* clear the mess */
			cmd = malloc(25);
			i = 0;
			
			vga_puts("> ");
		}
		/* ignore spaces as first character and ignore more than one space */
		else if((c == ' ') && (i == 0 || cmd[i - 1] == ' '))
			continue;
		else if(c != '\b')
		{
			cmd[i] = c;
			i++;
		}
		else
		{
			/* we don't want a negative i */
			if(i)
				i--;
			cmd[i] = 0;
		}
	}
}
