#include <u.h>
#include <libc.h>
#include <mem.h>

char*
strdup(char *s)
{
	char *dup;

	dup = malloc(strlen(s) + 1); /* s + \0 */
	return strncpy(s, dup, strlen(s));
}
