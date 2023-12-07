#include <u.h>
#include <libc.h>
#include <err.h>
#include <vfs.h>

static int
usage()
{
	printf("ls: usage: ls [-l] dir\n");
	return USAGE;
}

char*
permtoletter(uint16 perms)
{
	char *s;
	int i, j;
	s = malloc(16);

	i = 6; /* most significant bit */
	j = 0;

	while(i >= 0)
	{
		s[j++] = (perms & (4 << i)) ? 'r' : '-';
		s[j++] = (perms & (2 << i)) ? 'w' : '-';
		s[j++] = (perms & (1 << i)) ? 'x' : '-';
		
		/* we iterate 3 bits each time */
		i -= 3;
	}
		
	s[j++] = '\0';
	return s;
}


int
ls_main(int argc, char **argv)
{
	ll_t *t, *head;
	fs_t *fs;
	file_t *f, *dir;
	char *perms;
	int lflag;

	lflag = 0;
	if(argc == 1)
	{
		argv[1] = "/";
		argc = 2;
	}
	if(argc > 1 && !strcmp(argv[1], "-l"))
	{
		lflag = 1;
		argv++;
		argc--;
	}
	if(argc != 2)
		return usage();
	
	fs = getfs(argv[1]);
	if(fs == nil)
	{
		printf("No such fs\n");
		return NO_SUCH_FS;
	}
	
	dir = pathtofile(fs, argv[1], nil);
	if(dir == nil)
	{
		printf("No such file\n");
		return NO_SUCH_FILE;
	}

	head = dirread(fs, dir); 
	t = (ll_t*)head->next; /* first entry is always trash */
	
	while(t != nil)
	{
		f = ((file_t*)t->val);
		if(lflag)
		{
			printf("%d\t", f->fid);
			printf("%d\t", f->size);

			printf("%d\t", f->owner);
			printf("%s\t", permtoletter(f->perms));

			printf("%s", f->path);
			printf("%s\n", f->name);
		}
		else
		{
			printf("%s", f->path);
			printf("%s\n", f->name);
		}

		t = (ll_t*)t->next;
	}
	
	llfree(head);
	free(perms);
	return OK;
}
