#include <u.h>
#include <libc.h>
#include <mem.h>
#include <cons.h>
#include <user.h>
#include <x86.h>

#include "../cmd/rc.h"

/* abandon hope, all ye who enter here */
void
panic(void)
{
	cons_write(pccons, "PANIC!\n");
	cons_write(serialcons, "PANIC!\n");
	outb(KBC, 0xFE);
}

void
kernel_main(void) 
{
	/* set up memory map */
	memset(memap, FREE, MEM_MAX * (1024 / BLOCKSIZE));

	cons_init(pccons);
	cons_write(bitcons, "Teppich");
	users_init();
	cuser = adam;

	rc_main();
}
