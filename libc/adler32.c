#include <u.h>
#include <libc.h>

long
adler32(char *data)
{
	const int prime = 65521;
	int i = 0;
	int a = 0, b = 1;
	while (i < strlen(data))
	{
		b += data[i];
		a += b;
		i++;
	}
	b = b % prime;
	a = a % prime;
	return(b << 16 | a);
}