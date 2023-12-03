#pragma once
#include <vfs.h>

extern fs_t* cmdfs_init(void);
extern fs_t* rootfs_init(void);
extern fs_t* envfs_init(void);

static mnt_t fstab[] =
{
	{"/", rootfs_init},
	{"/cmd/", cmdfs_init},
	{"/env/", envfs_init},
};
