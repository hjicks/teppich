#include <u.h>
#include <libc.h>
#include <err.h>
#include <user.h>
#include <ps2.h>

#include <mem.h>

char answers[32][256] =
{
	"Authtication failure\n",

	/* uhh... */
	"Better luck next time!\n",
	"Try harder.\n",
	"lol.\n",
	"Nice try.\n",
	"Use hashcat.\n",
	"Not even close.\n",
	"Yawn...\n",
	"Did you expected me to accept this?\n",
	"Segmention fault\n",
	"Segmention fault (core dumped)\n"
	"Divison by zero\n",
	"General protection fault\n",
	"login 6817489: suicide: invalid address 0x0/0 in sys call pc=0x40cf\n",
	"Click here to reset your password.\n",
	"Consider this as a BSOD.\n",
	"Cry about it.\n",
	"This password is already used by <nil>.\n",
	"my aunt could type better than you\n",

	"login.exe has stopped working\n"
	"A problem caused the program to stop working correctly."
	"Teppich will close the program and notify you if a solution is available.\n",
};

static int
usage()
{
	printf("usage: login username\n");
	return USAGE;
}

static int
checkpass(char *pass, user_t *u)
{
	if(u != nil && u->pass == adler32(pass))
		return OK;
	return INCORRECT_PASSWD;
}

int
login_main(int argc, char **argv)
{
	int i;
	char c, *p;
	ll_t *t;
	user_t *u;


	if(argc != 2)
		return usage();

	u = nil;
	t = users;
	/* search for user */
	while(t != nil)
	{
		u = (user_t*)t->val;
		if(!strcmp(u->name, argv[1]))
			break;
		t = (ll_t*)t->next;
	}
	printf("Password: ");
	i = 0;
	p = malloc(PASSWD_MAX);
	
	while(i < PASSWD_MAX - 1)
	{
		c = ps2_getc();
		
		if(c == '\b')
		{
			if(i)
				i--;
			p[i] = '\0';
			printf("\b");
			continue;
		}
		else if(c == '\r')
		{
			p[i] = '\0';
			break;
		}
		p[i] = c;
		printf("*");
		i++;
	}
	printf("\n");
	

	if(i > PASSWD_MAX)
	{
		printf("\noverflow!\n");
		return OVERFLOW;
	}

	if(checkpass(p, u) == OK)
	{
		cuser = *u;
		return OK;
	}
	else
	{
		printf("%s", answers[(i) % (sizeof(answers) / sizeof(char*))]);
		return AUTH_FAILED;
	}
}
