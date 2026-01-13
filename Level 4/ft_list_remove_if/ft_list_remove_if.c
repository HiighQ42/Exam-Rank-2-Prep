#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*curr;
	t_list	*prev;

	/* Kopf der Liste entfernen, solange er passt */
	while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
	{
		curr = *begin_list;
		*begin_list = (*begin_list)->next;
		free(curr);
	}

	prev = *begin_list;
	if (!prev)
		return ;

	curr = prev->next;
	while (curr)
	{
		if (cmp(curr->data, data_ref) == 0)
		{
			prev->next = curr->next;
			free(curr);
			curr = prev->next;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}