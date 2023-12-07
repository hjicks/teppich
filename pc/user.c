#include <u.h>
#include <libc.h>
#include <user.h>
#include <mem.h>
#include <err.h>
#include <cons.h>

static user_t *cuser;
static ll_t *users;

static user_t adam =
{
	.uid = 1,
	.name = "adam",
};

static int
validatename(char *s)
{
	for(int i = 0 ; i < strlen(s) ; i++)
	{
		if(!isalpha(s[i]))
			return INVALID_USERNAME;
	}
	return OK;
}

static int
validatepass(char *s)
{
	if(strlen(s) < PASSWD_MAX)
		return INVALID_PASSWD;

	return OK;
}

static user_t*
finduser(int uid)
{
	ll_t *t;
	user_t *u;

	t = users;
	/* search for user */
	while(t != nil)
	{
		u = (user_t*)t->val;
		if(u->uid == uid)
			break;
		t = (ll_t*)t->next;
	}
	/* if t is nil, then there was no users */
	if(t == nil)
		return nil;
	else
		return u;
}

static int
checkpass(uint8 uid, char *pass)
{
	user_t *u;

	u = finduser(uid);
	if(u != nil && u->pass == adler32(pass))
		return OK;

	return INCORRECT_PASSWD;
}

void
users_init(void)
{
	users = (ll_t*)malloc(sizeof(ll_t));
	adam.pass = adler32("1234");
	users->val = &adam;
	users->next = nil;
}

user_t*
useradd(char *name, char *pass)
{
	ll_t *t;
	user_t *u, *lastuser;

	if(validatename(name) != OK)
		return nil;

	if(validatepass(pass) != OK)
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
	lastuser = u; /* needed for uid */

	u = (user_t*)malloc(sizeof(user_t));
	u->uid = lastuser->uid + 1;
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

char*
getpass(char *prompt, char *str)
{
	int i;
	char c;

	i = 0;
	printf("%s", prompt);
	while(1)
	{
		c = cons_read(defcons);
		
		if(c == '\r')
		{
			str[i] = '\0';
			break;
		}
		else if(i >= PASSWD_MAX - 1) /* silently ignore */
			continue;
		else if(c == '\b')
		{
			if(i)
				i--;
			str[i] = '\0';
			continue;
		}

		str[i] = c;
		i++;
	}
	printf("\n");
	return str;
}

int
getuser(char *username)
{
	ll_t *t;
	user_t *u;

	t = users;
	/* search for user */
	while(t != nil)
	{
		u = (user_t*)t->val;
		if(!strcmp(u->name, username))
			break;
		t = (ll_t*)t->next;
	}
	if(u == nil)
		return NO_SUCH_USER;
	else
		return u->uid;
}

user_t*
getcuser(void)
{
	user_t *u;

	u = (user_t*)malloc(sizeof(user_t));
	return memcpy(u, cuser, sizeof(user_t));
}

user_t*
getadam(void)
{
	user_t *u;

	u = (user_t*)malloc(sizeof(user_t));
	return memcpy(u, &adam, sizeof(user_t));
}

int
setcuser(uint8 uid, char *pass)
{
	if(checkpass(uid, pass) == OK)
	{
		/* finduser might return nil, but checkpass wont be OK before that happens */
		cuser = finduser(uid);
		return OK;
	}
	return INCORRECT_PASSWD;
}
