#pragma once
#include <u.h>

#define NAME_MAX 64
#define PATH_MAX 64

enum
{
	NOTREADY = 0,
	READY
}FS_STATE;

typedef struct
{
	uint32 fid;
	uint32 size;

	uint16 owner;
	uint16 group;
	uint16 muser;
	
	uint16 perms;
	
	uint32 mtime;
	uint32 ctime;

	char *name;
	char *path;

	char *buf;
	
}file_t;

typedef struct
{
	uint32 fid;

	uint8 state; /* FS_TYPES */
	
	ll_t *users;
	ll_t *files;
}fs_t;

typedef struct
{
	char *name;
	fs_t* (*init)();
}mnt_t;

ll_t* readdir(fs_t *fs, file_t *dir);
file_t* pathtofile(fs_t *fs, char *path, char *name);
fs_t* getfs(char *path);
