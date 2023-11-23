#include <u.h>

char*
strncpy(char *dst, const char *src, size_t num)
{
	char *dst_p = dst;

	if (num != 0) {

		do {
			if ((*dst++ = *src++) == 0) {
				/* NULL pad the remaining n-1 bytes */
				while (--num != 0)
					*dst++ = 0;
				break;
			}
		} while (--num != 0);
	}
	return (dst_p);
}
