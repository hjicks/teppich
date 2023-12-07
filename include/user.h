#pragma once
#define PASSWD_MAX 16
#define USERNAME_MAX 8

typedef struct
{
	uint8 uid;
	char *name;
	long pass; /* adler32 hash */
}user_t;

void users_init(void);
int getuser(char *username);
char* getpass(char *prompt, char *user);
int setcuser(uint8 uid, char *pass);
user_t* getcuser(void);
user_t* getadam(void);
