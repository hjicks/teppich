/* deletes the next entry in the list */
int
lldel(ll_t *ll)
{
	ll_t *temp = ll->next;
	if(ll->next != nil)
		return LL_ERR;

	ll->next = ll->next->next;
	free(temp);
	return OK;
}
