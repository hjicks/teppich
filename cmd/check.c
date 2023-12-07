/* health check, stuff should look fine */

#include <u.h>
#include <libc.h>
#include <err.h>

#include <mem.h>
#include <vga.h>
#include <ps2.h>

typedef struct
{
	char *name;
	void (*fn)();
}tbl;

static void malloc_test(void);
static void vga_test(void);

static tbl tests[] =
{
	{"malloc", malloc_test},
	{"vga", vga_test},
};

static void
malloc_test(void)
{
	void *a, *b, *c;

	a = malloc(1);
	b = malloc(2);
	c = malloc(3);

	printf("a = %x\n", a);
	printf("b = %x\n", b);
	printf("c = %x\n", c);

	printf("a location in memap = %x\n", ((int)(a) - MEM_BEG) / BLOCKSIZE);
	printf("b location in memap = %x\n", ((int)(b) - MEM_BEG) / BLOCKSIZE);
	printf("c location in memap = %x\n", ((int)(c) - MEM_BEG) / BLOCKSIZE);

	printf("memap[a] = %x\n", memap[(((int)(a) - MEM_BEG) / BLOCKSIZE) + 1]);
	printf("memap[b] = %x\n", memap[(((int)(b) - MEM_BEG) / BLOCKSIZE) + 1]);
	printf("memap[c] = %x\n", memap[(((int)(c) - MEM_BEG) / BLOCKSIZE) + 1]);

	free(a);
	free(b);
	free(c);
	memory_main(0, nil);
}

static void
vga_test(void)
{
	char c, *s;
	uint8 oldcolor;

	s = malloc(10);
	s = "Hello from VGA driver.\n";

	vga_puts("vga_puts(): ");
	vga_puts(s);
	
	vga_puts("vga_putc(): ");
	for(int i = 0 ; i < strlen(s) ; i++)
		vga_putc(s[i]);

	vga_puts("dynamic \\t support:\n");
	vga_puts("1\t  2\tabc\t   \td\n");

	vga_puts("vga_writeto(): ");
	for(int i = 0 ; i < strlen(s) ; i++)
		vga_writeto(s[i], vga_color, vga_row, vga_col);
	
	vga_puts("\n");
	oldcolor = vga_color;
	vga_color = BLACK | RED << 4;
	vga_puts("you should see this in color: ");
	vga_puts(s);
	vga_color = oldcolor;
	
	vga_puts("testing scroll");
	vga_scroll();
	
	free(s);
}

int
check_main(int argc, char **argv)
{
	char c;

	for(int i = 0 ; i < (sizeof(tests) / sizeof(tbl)) ; i++)
	{
		vga_clear(' ');
		printf("%s test\n", tests[i].name);
		tests[i].fn();
		printf("press any key to continue\n");
		scanf("%c", &c);
	}
	return OK;
}
