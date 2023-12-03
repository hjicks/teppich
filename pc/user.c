#include <u.h>
#include <libc.h>
#include <user.h>
#include <mem.h>
#include <err.h>

user_t adam =
{
	.id = 1,
	.name = "adam",
};

user_t cuser;
ll_t *users;

static int
checkname(char *s)
{
	for(int i = 0 ; i < strlen(s) ; i++)
	{
		if(!isalpha(s[i]))
			return INVALID_USERNAME;
	}
	return OK;
}

static int
checkpass(char *s)
{
	if(strlen(s) < PASSWD_MAX)
		return INVALID_PASSWORD;

	return OK;
}

void
users_init(void)
{
	users = malloc(sizeof(ll_t*));
	adam.pass = adler32("1234");
	users->val = &adam;
	users->next = nil;
}

user_t*
useradd(char *name, char *pass)
{
	ll_t *t;
	user_t *u;

	if(checkname(name) != OK)
		return nil;

	if(checkpass(pass) != OK)
		return nil;

	/* check if there are any duplicates */
	t = users;
	while(t != nil)
	{
		u = t->val;
		if(!strcmp(name, u->name))
			return nil;
		t = (ll_t*)t->next;
	}

	u = (user_t*)malloc(sizeof(user_t));
	u->id = lastuser->id + 1;
	u->name = name;
	u->pass = adler32(pass);

	lladd(t, u);
	return u;
}

/* TODO: fix deleting first entry in users */
int
userdel(user_t* user)
{
	ll_t *t, *prev;
	user_t *u;

	t = users;
	while(t != nil)
	{
		prev = t;
		u = t->val;
		if(u = user)
			break;
		t = (ll_t*)t->next;
	}
	if(t = nil)
		return NO_SUCH_USER;

	return lldel(t);
}
