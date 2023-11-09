#include <u.h>
#include <libc.h>
#include <vga.h>

static inline uint8
vga_gencolor(int fg, int bg)
{
	return fg | bg << 4;
}

static inline uint16
vga_char(unsigned char c, uint8 color)
{
	return (uint16) c | (uint16) color << 8;
}

void
vga_clear(char c)
{
	for (size_t y = 0; y < VGA_HEIGHT; y++)
	{
		for (size_t x = 0; x < VGA_WIDTH; x++)
		{
			const size_t index = y * VGA_WIDTH + x;
			vga_buf[index] = vga_char(c, vga_color);
		}
	}
}

void
vga_init(int fg, int bg)
{
	vga_row = 0;
	vga_col = 0;
	vga_color = vga_gencolor(fg, bg);
	vga_buf = (uint16*) 0xB8000;
	vga_clear(' ');
}

void
vga_writeto(char c, uint8 color, int x, int y)
{
	int index = y * VGA_WIDTH + x;
	vga_buf[index] = vga_char(c, color);
}


void
vga_nl(void)
{
	vga_col = 0; /* cr */
	if(++vga_row == VGA_HEIGHT) /* lf */
		vga_row = 0;
	
}

void
vga_putc(char c)
{
	switch(c)
	{
		case '\n':
			vga_nl();
			return;
		case '\t':
			for(int i = 0 ; i < 4 ; i++)
				vga_putc(' ');
			return;
		default:
			vga_writeto(c, vga_color, vga_col, vga_row);
			if(++vga_col == VGA_WIDTH)
			vga_nl();
	}
}

void
vga_puts(char *s)
{
	int len = strlen(s);
	for(int i = 0 ; i < len ; i++)
		vga_putc(s[i]);
}
