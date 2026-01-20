#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *curr;
    t_list *prev;

    while(*begin_list && !cmp((*begin_list)->data, data_ref))
    {
        curr = *begin_list;
        *begin_list = (*begin_list)->next;
        free(curr);
    }
    
    prev = *begin_list;
    if(!prev)
        return ;
    curr = prev->next;
    while (curr)
    {
        if(!cmp(curr->data, data_ref))
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

t_list *newnode (int value)
{
    t_list *node = malloc(sizeof(t_list));
    int *data = malloc(sizeof(int));

    *data = value;
    node->data = data;
    node->next = NULL;

    return node;
}

void print_lst(t_list *lst)
{
    while (lst)
    {
        printf("%d -> ", *(int *)lst->data);
        lst = lst->next;
    }
    printf("NULL\n");
}
int cmp_int(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

int main (void)
{
    t_list *list = NULL;

    list = newnode(5);
    list->next = newnode(7);
    list->next->next = newnode(5);
    list->next->next->next = newnode(42);
    list->next->next->next->next = newnode(42);

    printf("before :\n");
    print_lst(list);
    printf("\n after :\n");
    int ref = 42;
    ft_list_remove_if(&list, &ref, cmp_int);
    print_lst(list);



}