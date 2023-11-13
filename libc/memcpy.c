void*
memcpy(void *a1, void *a2, unsigned int len)
{
	char *s1, *s2;

	s1 = a1;
	s2 = a2;
	if((s2 < s1) && (s2 + len > s1))
		goto back;
	while(len > 0) {
		*s1++ = *s2++;
		len--;
	}
	return a1;

back:
	s1 += len;
	s2 += len;
	while(len > 0) {
		*--s1 = *--s2;
		len--;
	}
	return a1;
}
