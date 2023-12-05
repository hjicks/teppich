#include <u.h>
#include <cons.h>
#include <x86.h>

/* abandon hope, all ye who enter here */
void
panic(void)
{
	cons_write(pccons, "PANIC!\n");
	cons_write(serialcons, "PANIC!\n");
	outb(KBC, 0xFE);
}
