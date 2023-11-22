#include <u.h>
#include <libc.h>

#include <mem.h>
	
char*
strcntok(char *src, char token, int n)
{
	int i, b, match, lastmatch, lastnotmatch;
	char *res;
			
	match = -1; /* n = 0, match++ = 0 */
	lastmatch = 0;
	i = 0;
	while(i < strlen(src))
	{
		if(src[i] == token)
		{
			match++;
			if(match == n)
			{
				res = malloc(i + 1 - lastmatch); /* i - lastmatch + '\0' */
				/* TODO: use strncpy */	
				memcpy(res, src + lastmatch, i - lastmatch);
				res[i - lastmatch] = '\0';
				return res;
			}

			lastmatch = i+1;
		}
		i++;
	}
	
	/* last instance would return anything left */
	if(n == match + 1)
	{
		res = malloc(i - lastmatch);
		memcpy(res, src + lastmatch, i - lastmatch);
		return res;	
	}
	return nil;
}
