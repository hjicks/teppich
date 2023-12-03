#include <u.h>
#include <libc.h>

#include <mem.h>

#include <vfs.h>
#include <user.h>
#include "../cmd/rc.h"
#include "fstab.h"

static fs_t *cmdfs;

fs_t*
cmdfs_init(void)
{
	char *path;
	int i = 0;
	ll_t *ulist, *flist, *t;
	file_t *f, *root;
	
	if(cmdfs->state == READY)
		return cmdfs;
		
	path = "/cmd/";
	cmdfs = (fs_t*)malloc(sizeof(fs_t));
	
	ulist = malloc(sizeof(ll_t*));
	flist = malloc(sizeof(ll_t*));

	lladd(ulist, &adam);
	
	cmdfs->fid = 1;
	cmdfs->state = READY;
	cmdfs->users = ulist;
	
	flist->next = nil;
	t = flist;
	
	/* set root up */
	root = (file_t*)malloc(sizeof(file_t));
	
	root->fid = 0;
	root->size = 0;
	
	root->owner = adam.id;
	root->perms = 0444; /* u=r, o=r */
	
	root->path = "/";
	root->name = "";

	/* root.buf = smh */
	
	flist->val = root;
	
	for(int i = 0 ; i < sizeof(cmdtab) / sizeof(prog_t) ; i++)
	{	
		f = (file_t*)malloc(sizeof(file_t));
		
		f->fid = cmdfs->fid++;
		f->size = 0; /* that is a virtual file */
		
		f->owner = adam.id;
		f->perms = 0555;
		
		f->name = cmdtab[i].name;
		f->path = malloc(sizeof(PATH_MAX));
		
		strncpy(f->path, path, strlen(path));
		
		/* f.buf = smh */
		lladd(t, f);
		
		t = (ll_t*)t->next;
	}

	cmdfs->files = flist;
	
	return cmdfs;
}

