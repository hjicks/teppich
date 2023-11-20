#include <u.h>
#include <libc.h>
#include <vga.h>
#include <bitmap.h>

void
bitputs(char *s)
{
	int line, chr, bit;
	int set;
	
	for(line = 0; line < 8 ; line++)
	{
		for(chr = 0; chr < strlen(s) ; chr++)
 		{
 			for(bit = 0; bit < 8 ; bit++)
 			{
				set = bitfont[s[chr]][line] & 1 << bit;
				vga_putc(set ? 178 : ' ');
			}
		}
		vga_putc('\n');
	}
	vga_putc('\n');
}

void
bitputc(char c)
{
	int line, bit;
	int set;
	
	for(line = 0 ; line < 8 ; line++)
	{
		for(bit = 0 ; bit < 8 ; bit++)
		{
			set = bitfont[c][line] & 1 << bit;
			vga_putc(set ? 178 : ' ');	
		}
		vga_putc('\n');
	}
}
