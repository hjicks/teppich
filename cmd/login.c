#include <u.h>
#include <libc.h>
#include <err.h>
#include <user.h>
#include <ps2.h>

#include <mem.h>

char answers[20][256] =
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
	"Segmention fault (core dumped)\n",
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
	printf("usage: login [username]\n");
	return USAGE;
}

int
login_main(int argc, char **argv)
{
	int uid;
	int status;
	int a; /* answer */
	char *username, *pass;
	ll_t *t;


	if(argc > 2)
		return usage();

	username = malloc(USERNAME_MAX);
	if(argc == 1)
	{
		printf("Username: ");
		scanf("%s", &username);
	}
	else
		strncpy(username, argv[1], USERNAME_MAX);
	
	uid = getuser(username); 
	pass = malloc(PASSWD_MAX);
	getpass("Password: ", pass);

	status = setcuser(uid, pass);

	/* never is too late to mock your users */
	a = (strlen(username) * (strlen(pass) * pass[strlen(pass-1)]) % (sizeof(answers) / sizeof(*answers)));
	free(pass);
	free(username);

	if(status != OK)
	{
		printf("%s", answers[a]);
		return AUTH_FAILED;
	}
	return OK;
}

