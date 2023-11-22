#include <u.h>
#include <err.h>
#include <mem.h>

/* deletes the next entry in the list */
int
lldel(ll_t *ll)
{
	ll_t *temp = ll->next;

	ll->next = temp->next;
	
	free(temp->val);
	free(temp);
	return OK;
}
