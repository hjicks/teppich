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

void consinit(consdev_t cons);
void consclear(consdev_t cons, char c);
void conswrite(consdev_t cons, char *s);
void consputc(consdev_t cons, char c);
char consread(consdev_t cons);
void consscroll(consdev_t cons, int lines);
