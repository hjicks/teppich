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
			uint16 index = y * VGA_WIDTH + x;
			vga_buf[index] = vga_char(c, vga_color);
		}
	}
	vga_row = 0;
	vga_col = 0;
}

void
vga_init(void)
{
	vga_row = 0;
	vga_col = 0;
	vga_color = vga_gencolor(WHITE, BLUE);
	vga_buf = (uint16*)VGA_MEM;
	vga_clear(' ');
}

void
vga_writeto(char c, uint8 color, int x, int y)
{
	int index = y * VGA_WIDTH + x;
	vga_buf[index] = vga_char(c, color);
}

void
vga_scroll()
{
	uint16 c;
	char *s;
	
	s = malloc(10);
	c = vga_char(' ', vga_color);

	for(int i = 0 ; i < VGA_WIDTH * VGA_HEIGHT ; i++)
		vga_buf[i] = vga_buf[i + VGA_WIDTH];
	
	/* clear last line */
	for(int i = VGA_WIDTH * (VGA_HEIGHT - 1) ; i < VGA_WIDTH * VGA_HEIGHT ; i++)
	{
		vga_buf[i] = c;
	}
}

void
vga_nl(void)
{
	vga_col = 0; /* cr */
	if(vga_row == VGA_HEIGHT - 1)
		vga_scroll();
	else
		vga_row++;
}

void
vga_putc(char c)
{
	switch(c)
	{
		case '\r':
		case '\n':
			vga_nl();
			return;
		case '\t':
			/* dynamic tab! */	
			int dst = (vga_col % 8);
			for(int i = 0 ; i < dst ; i++)
				vga_putc(' ');
			return;
		case '\b':
			if(vga_col > 0)
				vga_writeto(' ', vga_color, --vga_col, vga_row);

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
	int len;
	
	len = strlen(s);
	for(int i = 0 ; i < len ; i++)
		vga_putc(s[i]);
}
