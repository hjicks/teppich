#include <u.h>
#include <libc.h>

int
strccnt(char *s, char c)
{
	int i, t;
	
	i = 0;
	t = 0;
	while(i < strlen(s))
	{
		if(s[i] == c)
			t++;
		i++;
	}
	return t;
}
