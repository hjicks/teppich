/* 
	free all entries in a linked list,
	can, and will be dangerous
*/

#include <u.h>
#include <libc.h>
#include <mem.h>

void
llfree(ll_t *head)
{
	ll_t *t, *p;
	
	p = head;
	t = (ll_t*)head->next;
	while(t != nil)
	{
		free(p);
		p = t;
		t = (ll_t*)t->next;
	}
}
