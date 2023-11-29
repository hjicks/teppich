#include <x86.h>
#include <err.h>

int
reboot_main(int argc, char **argv, char *cwd)
{
	outb(KBC, 0xFE);
	return OK; /* we likely never get to here, maybe we should do noreturn */
}
