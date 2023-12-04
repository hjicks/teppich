#include <cons.h>
#include <vga.h>
#include <ps2.h>
#include <bitmap.h>
#include <com.h>

const consdev_t pccons = 
{
	.name = "cons",
	.init = vga_init,
	.clear = vga_clear,
	.puts = vga_puts,
	.putc = vga_putc,
	.getc = ps2_getc,
	.scroll = vga_scroll,
};

const consdev_t bitcons =
{
	.name = "bitcons",
	.init = vga_init,
	.clear = vga_clear,
	.puts = bitputs,
	.putc = bitputc,
	.getc = ps2_getc,
	.scroll = vga_scroll,
};

const consdev_t serialcons =
{
	.name = "serialcons",
	.init = com_init,
	/* .clear = nil */
	.puts = com_puts,
	.getc = com_getc,
	/* .scroll = nil */
};

consdev_t defcons = pccons;

void
cons_init(consdev_t cons)
{
	cons.init();
}

void
cons_clear(consdev_t cons, char c)
{
	cons.clear(c);
}

void
cons_putc(consdev_t cons, char c)
{
	cons.putc(c);
}

void
cons_write(consdev_t cons, char *s)
{
	cons.puts(s);
}

char
cons_read(consdev_t cons)
{
	return cons.getc();	
}
