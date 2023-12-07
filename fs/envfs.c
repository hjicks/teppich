#include <u.h>
#include <libc.h>
#include <err.h>
#include <vfs.h>
#include <mem.h>
#include <user.h>

static fs_t *envfs;
static user_t *cuser;

fs_t*
envfs_init(void)
{
	char *path;
	int i = 0;
	ll_t *ulist, *flist;
	file_t *root;

	/* TODO: check if user has changed, if yes. create a new envfs */
	if(envfs->state == READY)
		return envfs;
		
	envfs = (fs_t*)malloc(sizeof(fs_t));
	
	ulist = malloc(sizeof(ll_t*));
	flist = malloc(sizeof(ll_t*));

	cuser = getcuser();
	lladd(ulist, cuser);
	
	envfs->fid = 1;
	envfs->state = READY;
	envfs->users = ulist;
	
	/* set root up */
	root = (file_t*)malloc(sizeof(file_t));
	
	root->fid = 0;
	root->size = 0;

	root->owner = cuser->uid;
	root->perms = 0444; /* u=r, o=r */
	
	root->path = malloc(sizeof(PATH_MAX));
	strncpy(root->path, "/env/", strlen("/env/"));
	root->name = "";
	
	flist->val = root;
	flist->next = nil;

	envfs->files = flist;
	
	return envfs;

}

/* TODO: reject invalid names */
file_t*
envfs_create(char *name)
{
	char *path;
	ll_t *t;
	file_t *f;

	path = "/env/";

	t = envfs->files;
	while(t->next != nil)
		t = (ll_t*)t->next;

	f = (file_t*)malloc(sizeof(file_t));

	f->fid = envfs->fid++;
	f->perms = 0600;
	f->name = name;

	f->path = malloc(sizeof(PATH_MAX));
	strncpy(f->path, path, strlen(path));

	f->owner = cuser->uid;

	/* t now should point to last item in fs->files */
	lladd(t, f);

	return f;
}

int
envfs_new(char *name, char *buf)
{
	ll_t *t;
	file_t *f;
	if(envfs->state != READY)
		envfs_init();

	if(strlen(name) > NAME_MAX)
		return NAME_TOO_LONG;

	for(int i = 0 ; i < strlen(name) ; i++)
		if(!isalpha(name[i]))
			return INVALID_FILENAME;

	f = envfs_create(name);
	f->buf = malloc(strlen(buf));
	strncpy(f->buf, buf, strlen(buf));
	f->size = strlen(buf);

	return OK;	
}
