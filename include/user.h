#pragma once
#define PASSWD_MAX 16

typedef struct
{
	uint8 id;
	char *name;
	long pass; /* adler32 hash */
}user_t;

extern ll_t *users;
extern user_t cuser;
extern user_t adam;

void users_init(void);
