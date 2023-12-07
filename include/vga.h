#pragma once
#include <u.h>

#define VGA_MEM 0xB8000

static const uint8 VGA_WIDTH = 80; /* x */
static const uint8 VGA_HEIGHT = 25; /* y */

uint8 vga_row;
uint8 vga_col;

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

void vga_clear(char c);
void vga_init(void);
void vga_writeto(char c, uint8 color, int x, int y);
void vga_scroll(void);
void vga_nl(void);
void vga_putc(char c);
void vga_puts(char *s);
