#include <u.h>
#include <libc.h>
#include <ps2.h>
#include <err.h>
#include <user.h>
#include "rc.h"

static char *cwd;
static char *username;
static user_t *cuser;


int
exec(int argc, char* argv0, char **argv)
{
	int status;

	status = NO_SUCH_CMD;
	for(int i = 0 ; i < (sizeof(cmdtab) / sizeof(prog_t)) ; i++)
	{
		if(!strcmp(argv0, cmdtab[i].name))
			status = cmdtab[i].main(argc, argv);
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
		argv0 = strdup(cmd);
		if(argv0 == nil)
			return OK;

		argc = 0;
		/* shouldn't we do something regarding argv here? one wonders */
	}
	else
	{
		for(argc = 0 ; argc < (strccnt(cmd, ' ') + 1) ; argc++)
			argv[argc] = strcntok(cmd, ' ', argc);

		argv[argc+1] = '\0'; /* just in case */
	}

	return exec(argc, argv0, argv);
}

void
rc_main(void)
{
	int i;
	char c, *cmd;

	cwd = "/";
	i = 0;
	cmd = malloc(25);

	cuser = getcuser();
	printf("%s> ", cuser->name);
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

			printf("%s> ", cuser->name);
		}
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
			cmd[i] = '\0';
		}
	}
	free(cuser);
}
