#include <u.h>
#include <libc.h>

#include <mem.h>

#include <vfs.h>
#include <user.h>
#include "fstab.h"

static fs_t *rootfs;

fs_t*
rootfs_init(void)
{
	char* path;
	ll_t *ulist, *flist, *t;
	file_t *f, *root;
	user_t *u;

	if(rootfs->state == READY)
		return rootfs;
		
	path = "/";
	rootfs = (fs_t*)malloc(sizeof(fs_t));
	
	ulist = malloc(sizeof(ll_t*));
	flist = malloc(sizeof(ll_t*));

	u = getadam();
	lladd(ulist, u);
	
	rootfs->fid = 1;
	rootfs->state = READY;
	rootfs->users = ulist;
	
	root->fid = 0;
	root->size = 0;

	root->owner = u->uid;
	root->perms = 0444; /* u=r, o=r */
	
	root->path = "/";
	root->name = "";

	flist->val = root;
	flist->next = nil;
	t = flist;
	
	/* 
		fstab[0] is /
		TODO: call create() instead 
	*/
	
	for(int i = 1 ; i < sizeof(fstab) / sizeof(mnt_t) ; i++)
	{	
		f = (file_t*)malloc(sizeof(file_t));
		
		f->fid = rootfs->fid++;
		f->size = 0;
		
		f->owner = u->uid;
		f->perms = 0444;

		f->name = fstab[i].name;

		f->path = malloc(sizeof(char));
		strncpy(f->path, path, strlen(path));
		
		/* f.buf = */
		lladd(t, f);
		
		t = (ll_t*)t->next;
	}

	rootfs->files = flist;
	
	return rootfs;
}

