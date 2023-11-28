#include <u.h>
#include <libc.h>
#include "../cmd/rc.h"

#include <mem.h>

#include <vga.h>
#include <ps2.h>


/* abandon hope, all ye who enter here */
void
panic(void)
{
	vga_puts("panic: give up. it's over.\n");
}

void
kernel_main(void) 
{
	/* set up memory map */
	memset(memap, FREE, MEM_MAX * (1024 / BLOCKSIZE));

	vga_init();
	ps2_init();
	
	printf("Teppich\n");
	
	rc_main();
}
