#include "ft_list.h"
int	ft_list_size(t_list *begin_list)
{
    t_list *curr;
    int i = 0;
    curr = begin_list;

    while(curr)
    {
        curr = curr->next;
        i++;
    }
    return i;
}

#include <stdio.h>
#include <stdlib.h>


t_list *new_elem(void *data)
{
    t_list *node = malloc(sizeof(t_list));
    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

int main(void)
{
    t_list *list;
    t_list *n1;
    t_list *n2;
    t_list *n3;

    n1 = new_elem("Hello");
    n2 = new_elem("World");
    n3 = new_elem("!");

    n1->next = n2;
    n2->next = n3;
    list = n1;

    printf("List size: %d\n", ft_list_size(list));

    free(n1);
    free(n2);
    free(n3);

    return 0;
}
