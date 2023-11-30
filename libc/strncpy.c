#include <u.h>

char*
strncpy(char *dst, const char *src, size_t num)
{
	char *dst_p;

	dst_p = dst;
	while(*src != '\0' && num > 0)
	{
		*dst++ = *src++;
		num--;
	}
	if(*src != '\0')
		*dst = '\0';

	return (dst_p);
}
