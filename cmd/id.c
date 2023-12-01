#include <u.h>
#include <libc.h>
#include <user.h>
#include <err.h>

int
usage(void)
{
	printf("usage: id username\n");
	return USAGE;
}

int
id_main(int argc, char **argv)
{
	ll_t *t;
	user_t *u;

	if(argc != 2)
		return usage();

	u = nil;
	t = users;
	while(t != nil)
	{
		u = (user_t*)t->val;
		/* i wanted to add a iflag, but let it do both for now */
		if(!strcmp(u->name, argv[1]) || !strcmp(itoa(u->id, 10), argv[1]))
				break;
		u = nil;
		t = (ll_t*)t->next;
	}
	if(u == nil)
	{
		printf("No such user or id\n");
		return NO_SUCH_USER;
	}
	printf("username: %s\n", u->name);
	printf("id: %d\n", u->id);
	return OK;
}
