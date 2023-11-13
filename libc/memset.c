void*
memset(void* src, char c, unsigned int len)
{
	for (unsigned int i = 0; i < len; i++)
	{
		*(char*)(src++) = c;
	}
	return src;
}
