#include <vga.h>
#include <com.h>
#include <ps2.h>

/* abandon hope, all ye who enter here */
void panic(void)
{
	vga_puts("panic: give up. it's over.\n");
	com1_puts("panic: give up. it's over.\n");
}

void kernel_main(void) 
{
	vga_init(WHITE, BLUE);
	vga_puts("check out serial console");
	com1_puts("check out VGA console");
}
