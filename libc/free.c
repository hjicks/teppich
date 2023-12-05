#include <u.h>
#include <mem.h>

void
free(void *mem)
{
	int i;

	i = (((int)(mem) - MEM_BEG ) / BLOCKSIZE)+1;
	while(memap[i])
	{
		memap[i] = 0;
		*(char*)mem++ = '\0';
		i++;
	}
}
