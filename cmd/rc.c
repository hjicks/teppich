#include <u.h>
#include <libc.h>

#include <ps2.h>

#include <mem.h>
#include <err.h>
#include "rc.h"

static char *cwd;

int
exec(int argc, char* argv0, char **argv, char *cwd)
{
	int status;

	status = NO_SUCH_CMD;
	for(int i = 0 ; i < sizeof(cmdtab) ; i++)
	{
		if(!strcmp(argv0, cmdtab[i].name))
			status = cmdtab[i].main(argc, argv, cwd);
	}
	
	/* free the memory, whetever if we found a match or not */
	for(int j = 0 ; j < argc+1 ; j++)
		free(argv[j]);
	free(argv0);
	return status;
}

int
call(char *cmd)
{
	int argc, status;
	char *argv0, **argv;
	
	/* always always always
	check for nil pointers */
	
	argv0 = strcntok(cmd, ' ', 0);
	
	if(argv0 == nil)
	{
		argv0 = strdup(cmd); /* it still may be nil */
		argc = 0;
		/* shouldn't we do something regarding argv here? one wonders */
	}
	else
	{
		for(argc = 0 ; argc < (strccnt(cmd, ' ') + 1) ; argc++)
			argv[argc] = strcntok(cmd, ' ', argc);

		argv[argc+1] = '\0'; /* just in case */
	}

	return exec(argc, argv0, argv, cwd);
}

void
rc_main(void)
{
	char c;
	char *cmd;

	cwd = "/";
	int i = 0;
	cmd = malloc(25);
	
	printf("> ");
	while(1)
	{
		c = ps2_getc();
		printf("%c", c);
		
		if(c == '\r' || c == '\n')
		{
			cmd[i] = '\0';
			if(call(cmd) == NO_SUCH_CMD)
				printf("No such command\n");
			
			/* clear the mess */
			memset(cmd, '\0', 25);
			i = 0;
			
			printf("> ");
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
