#include <u.h>
#include <libc.h>
#include <err.h>

int
lladd(ll_t *last, void *data)
{
	ll_t *temp;

	if(last->next != nil)
		return LL_ERR;

	temp = (ll_t*)malloc(sizeof(ll_t));
	
	temp->val = data;
	temp->next = nil;
	
	last->next = temp;
	return OK;
}
