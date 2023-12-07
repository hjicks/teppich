#include <u.h>
#include <libc.h>

#include <mem.h>
#include <err.h>

int
memory_main(int argc, char **argv)
{
	int free, taken;


	free = 0;
	taken = 0;
	for(int i = 0 ; i < sizeof(memap) ; i++)
	{
		if(memap[i] == FREE)
			free++;
		else
			taken++;		
	}

	printf("free memory: %dB\t", free * BLOCKSIZE);
	printf("taken memory: %dB\n", taken * BLOCKSIZE);
	return OK;
}
