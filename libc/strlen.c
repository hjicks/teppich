int
strlen(char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return i;
}