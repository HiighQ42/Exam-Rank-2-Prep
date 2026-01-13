#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*cur;
	int		tmp;
	int		sorted;

	if (!lst)
		return (lst);

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		cur = lst;
		while (cur->next)
		{
			if (!cmp(cur->data, cur->next->data))
			{
				tmp = cur->data;
				cur->data = cur->next->data;
				cur->next->data = tmp;
				sorted = 0;
			}
			cur = cur->next;
		}
	}
	return (lst);
}