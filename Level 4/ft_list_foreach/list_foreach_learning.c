#include "ft_list.h"
void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    while(begin_list)
    {
        f(begin_list->data);
        begin_list = begin_list->next;
    }

}
#include <stdio.h>
#include <stdlib.h>

/* function to apply */
void	print_data(void *data)
{
	printf("%s\n", (char *)data);
}



int	main(void)
{
	t_list *n1;
	t_list *n2;
	t_list *n3;

	n1 = malloc(sizeof(t_list));
	n2 = malloc(sizeof(t_list));
	n3 = malloc(sizeof(t_list));

	n1->data = "Hello";
	n2->data = "42";
	n3->data = "Vienna";

	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;

	ft_list_foreach(n1, print_data);

	free(n1);
	free(n2);
	free(n3);

	return (0);
}
