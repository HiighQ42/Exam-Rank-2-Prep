#include "ft_list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list *curr;
    int tmp;
    int sorted = 0;

    while(sorted == 0)
    {
        sorted = 1;
        curr = lst;
        while(curr->next)
        {
            if(!cmp(curr->data, curr->next->data))
            {
                tmp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = tmp;
                sorted = 0;
            }
            curr = curr->next;
        } 
    }
    return lst;
}

#include <stdio.h>
#include <stdlib.h>

/* cmp function: ascending order */
int ascending(int a, int b)
{
	return (a <= b);
}

/* helper to create a new node */
t_list *new_node(int value)
{
	t_list *node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = value;
	node->next = NULL;
	return (node);
}

/* helper to print list */
void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d", lst->data);
		if (lst->next)
			printf(" -> ");
		lst = lst->next;
	}
	printf("\n");
}

int main(void)
{
	t_list *lst;

	/* build list: 3 -> 1 -> 4 -> 2 -> 2 */
	lst = new_node(3);
	lst->next = new_node(1);
	lst->next->next = new_node(4);
	lst->next->next->next = new_node(2);
	lst->next->next->next->next = new_node(2);

	printf("Before sort:\n");
	print_list(lst);

	lst = sort_list(lst, ascending);

	printf("After sort:\n");
	print_list(lst);

	return (0);
}
