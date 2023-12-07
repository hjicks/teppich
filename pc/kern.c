#include <u.h>
#include <libc.h>
#include <mem.h>
#include <cons.h>
#include <user.h>
#include <err.h>

#include "../cmd/rc.h"

void
kernel_main(void) 
{
	/* set up memory map */
	memset(memap, FREE, MEM_MAX * (1024 / BLOCKSIZE));

	cons_init(pccons);
	cons_write(bitcons, "Teppich");
	users_init();

	while(1)
	{
		if(login_main(1, nil) != OK)
			continue;

		rc_main();
	}
}
