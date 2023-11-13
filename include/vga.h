#pragma once
#include <u.h>

static const size_t VGA_WIDTH = 80; /* x */
static const size_t VGA_HEIGHT = 25; /* y */

size_t vga_row;
size_t vga_col;

uint8 vga_color;
uint16* vga_buf;

enum {
	BLACK = 0,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LIGHT_GREY,
	DARK_GREY,
	LIGHT_BLUE,
	LIGHT_GREEN,
	LIGHT_CYAN,
	LIGHT_RED,
	LIGHT_MAGENTA,
	LIGHT_BROWN,
	WHITE,
};

static uint8 vga_gencolor(int fg, int bg);
static uint16 vga_char(unsigned char c, uint8 color);
void vga_clear(char c);
void vga_init(int fg, int bg);
void vga_writeto(char c, uint8 color, int x, int y);
void vga_nl(void);
void vga_putc(char c);
void vga_puts(char *s);
