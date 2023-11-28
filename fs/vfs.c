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
readdir(fs_t *fs, file_t *dir)
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
			flist_last = flist_last->next;
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
			/* n = f->name; */
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
			/* n = f->name; */
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
	for(int i = 0 ; i < sizeof(fstab) ; i++)
	{
		if(!strcmp(path, fstab[i].name))
			return fstab[i].init();
	}
	return nil;
}
