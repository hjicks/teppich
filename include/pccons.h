#pragma once
#include <cons.h>
#include <vga.h>
#include <ps2.h>

consdev_t pccons = 
{
	.name = "cons",
	.init = vga_init,
	.clear = vga_clear,
	.puts = vga_puts,
	.putc = vga_putc,
	.getc = ps2_getc,
	
};
