/* health check, stuff should look fine */

#include <u.h>
#include <libc.h>

#include <err.h>
#include <mem.h>

void
malloc_test(void)
{
	void *a, *b, *c;
	 
	a = malloc(1);
	b = malloc(2);
	c = malloc(3);

	printf("a = %x\n", a);
	printf("b = %x\n", b);
	printf("c = %x\n", c);

	printf("a location in memap = %x\n", ((int)(a) - MEM_BEG) / BLOCKSIZE);
	printf("b location in memap = %x\n", ((int)(b) - MEM_BEG) / BLOCKSIZE);
	printf("c location in memap = %x\n", ((int)(b) - MEM_BEG) / BLOCKSIZE);

	printf("memap[a] = %x\n", memap[(((int)(a) - MEM_BEG) / BLOCKSIZE) + 1]);
	printf("memap[b] = %x\n", memap[(((int)(b) - MEM_BEG) / BLOCKSIZE) + 1]);
	printf("memap[c] = %x\n", memap[(((int)(c) - MEM_BEG) / BLOCKSIZE) + 1]);

	free(a);
	free(b);
	free(c);
}

int
check_main(int argc, char **argv)
{
	malloc_test();
	printf("Press any key to quit test\n");
	scanf("");
	return OK;
}
