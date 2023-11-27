#include <u.h>

int
lllen(ll_t *head)
{
	int i;
	ll_t *t;
	
	t = head;
	i = 0;
	while(t != nil)
	{
		i++;
		t = t->next;
	}
	return i;
}
