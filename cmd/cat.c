#include <u.h>
#include <libc.h>

#include <vfs.h>
#include <err.h>

#include <mem.h>

static int
usage(void)
{
	printf("usage: cat file");
	return USAGE;
}

int
cat_main(int argc, char **argv)
{
	char *name, *path;
	file_t *f;
	char *buf;
	int size;
	
	for(int i = 1 ; i < argc ; i++)
	{
		name = strcntok(argv[i], '/', strccnt(argv[i], '/'));
		if(name == nil)
			return usage();

		path = dirname(argv[i], '/');
		if(path == nil)
			return usage();

		f = pathtofile(getfs(path), path, name);

		buf = f->buf;
		size = f->size;

		while(*buf != '\0' && size > 0)
		{
			printf("%c", *buf);
			size++;
			buf++;
		}
		free(path);
	}
	
	free(name);
	return OK;
}
