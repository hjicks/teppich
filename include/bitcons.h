#pragma once
#include <cons.h>
#include <vga.h>
#include <ps2.h>
#include <bitmap.h>

consdev_t bitcon = 
{
	.name = "bitcon",
	.init = vga_init,
	.clear = vga_clear,
	.puts = bitputs,
	.putc = bitputc,
	.getc = ps2_getc,
	.scroll = vga_scroll,
};
