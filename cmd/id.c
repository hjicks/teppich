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
	int uid;
	user_t u;

	if(argc != 2)
		return usage();

	uid = getuser(argv[1]);

	if(uid < 0)
	{
		printf("No such user or id\n");
		return NO_SUCH_USER;
	}
	printf("username: %s\n", argv[1]);
	printf("id: %d\n", uid);
	return OK;
}
