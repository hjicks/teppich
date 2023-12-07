/* 
	vfs, maybe…
	You always think you know what you're doing,
	but you're too slick for your own good.
	-- Delphi's oracle
*/
#include <u.h>
#include <libc.h>
#include <vfs.h>
#include <err.h>
#include <user.h>
#include <mem.h>

#include "fstab.h"

ll_t*
dirread(fs_t *fs, file_t *dir)
{
	int i;
	ll_t *t, *flist, *flist_last;
	file_t *f;
	char *path;
	
	path = dir->path;
	flist = (ll_t*)malloc(sizeof(ll_t));
	
	flist->val = nil;
	flist->next = nil;
	
	flist_last = flist;
	
	t = fs->files->next;
	while(t != nil)
	{
		f = t->val;
		if(!strcmp(path, f->path))
		{
			lladd(flist_last, f);
			flist_last = (ll_t*)flist_last->next;
		}
		
		t = (ll_t*)t->next;
	}

	return flist;
}

file_t*
pathtofile(fs_t *fs, char *path, char *name)
{
	char *p, *n;
	ll_t *t;
	file_t *f;

	t = fs->files;
	if(name == nil) /* dir */
	{
		while(t != nil)
		{
			f = (file_t*)t->val;
			p = f->path;

			if(!strcmp(path, p))
				return f;
		
			t = (ll_t*)t->next;
		}
	}
	else /* file */
	{
		while(t != nil)
		{
			f = (file_t*)t->val;
			p = f->path;
			n = f->name;
			if(!strcmp(path, p) && !strcmp(name, n))
				return f;
		
			t = (ll_t*)t->next;
		}
	}
	
	return nil;
}

fs_t*
getfs(char *path)
{
	for(int i = 0 ; i < sizeof(fstab) / sizeof(mnt_t) ; i++)
	{
		if(!strcmp(path, fstab[i].name))
			return fstab[i].init();
	}
	return nil;
}

/* works like basename -d, sorta */
char*
dirname(char *s, char c)
{
	int last;
	
	last = 0;
	for(int i = 0 ; i < strlen(s) ; i++)
	{
		if(s[i] == c)
			last = i;
	}

	if(last == 0)
		return nil;

	return strncpy(s, s, last);
}
