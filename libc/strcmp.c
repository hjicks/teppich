int
strcmp(char *s1, char *s2)
{
	char c1, c2;

	while(1)
	{
		c1 = *s1++;
		c2 = *s2++;
		if(c1 != c2)
		{
			if(c1 > c2)
				return 1;
			return -1;
		}
		if(c1 == 0)
			return 0;
	}
}
