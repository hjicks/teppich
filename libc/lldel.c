#include <u.h>
#include <libc.h>
#include <err.h>


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
