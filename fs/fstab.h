#pragma once
#include <vfs.h>

fs_t* cmdfs_init(void);
fs_t* rootfs_init(void);

static mnt_t fstab[] =
{
	{"/", rootfs_init},
	{"/cmd/", cmdfs_init},
};
