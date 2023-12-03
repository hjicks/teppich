#pragma once
typedef struct
{
	char *name;
	
	void (*init)(void);
	void (*clear)(char);
	void (*puts)(char *s);
	void (*putc)(char c);
	char (*getc)(void);
	void (*scroll)(int lines);
}consdev_t;

extern consdev_t pccons;
extern consdev_t bitcons;
extern consdev_t serialcons;

void cons_init(consdev_t cons);
void cons_clear(consdev_t cons, char c);
void cons_write(consdev_t cons, char *s);
void cons_putc(consdev_t cons, char c);
void cons_puts(consdev_t cons, char *s);
char cons_read(consdev_t cons);
void cons_scroll(consdev_t cons, int lines);
