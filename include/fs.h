#include <u.h>

#define NAME_MAX 16

enum
{
	DIR,
	FILE,
	VFILE, /* shell files */
};

typedef struct
{
	uint32 inode;
	uint32 size;

	uint8 owner;
	uint8 perms;

	uint8 type;

	char *name;
	char **path; /* "/" "usr/" "local" */

	char *content;
	
}file_t;

typedef struct
{
	uint32 inode;

	uint8 encryption;
	uint8 compression;

	uint8 type;
	uint8 *start;

	ll_t users;
	ll_t files;
}fs_t;
