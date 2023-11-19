#include <cons.h>

void
consinit(consdev_t cons)
{
	cons.init();
}

void
consclear(consdev_t cons, char c)
{
	cons.clear(c);
}

void
consputc(consdev_t cons, char c)
{
	cons.putc(c);
}

void
conswrite(consdev_t cons, char *s)
{
	cons.puts(s);
}

char
consread(consdev_t cons)
{
	return cons.getc();	
}
