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
				res = (char*)malloc(i + 1 - lastmatch); /* i - lastmatch + '\0' */
				strncpy(res, src + lastmatch, i - lastmatch);
				return res;
			}

			lastmatch = i+1;
		}

		i++;
	}
	
	/* last instance would return anything left */
	if(match == n - 1)
	{
		res = (char*)malloc(i + 1 - lastmatch);
		strncpy(res, src + lastmatch, i - lastmatch);
		return res;
	}
	return nil;
}
