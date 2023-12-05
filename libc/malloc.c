#include <u.h>
#include <libc.h>
#include <mem.h>
#include <err.h>

static int
_malloc(uint16 size)
{
	int i, j;
	uint16 fmem; /* number of free segments */

	if(size > MEM_MAX * BLOCKSIZE)
		return NO_MEM;

	i = 0;
	fmem = 0;
	while(i < MEM_MAX * (1024 / BLOCKSIZE))
	{
		if(memap[i] == FREE)
		{
			fmem++;
			if(fmem == size+1) /* one bit for padding */
			{
	
				/* we are done here, give address */
				for(j = i ; j > i - size; j--)
					memap[j] = TAKEN;
			 	return i - size;
			}
		}
		else
			fmem = 0; /* we need continuous(?) memory */
		i++;
	}	

	/* where is your memory now? go ahead, do panic. */
	panic();
	return NO_MEM;
}

void*
malloc(uint16 size)
{
	int t;
	
	if(size == 0)
		return nil;

	t = _malloc(size);

	if(t == NO_MEM)
	/* LEST THAT HAPPEN, THOU SHALL NOT BE HERE */
		return nil;

	return (void*)(t * ( BLOCKSIZE ) + MEM_BEG);
}
