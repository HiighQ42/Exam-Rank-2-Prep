void sort_int_tab(int *tab, unsigned int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while(i < size)
    {
        j = 0;
        while (j + 1 < size)
        {
            if(tab[j] < tab[j + 1])
            {
                tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
}
#include <stdio.h>

/* Prototype of your function */

int main(void)
{
    int tab[] = {5, 2, 9, 2, 1, 5, 6};
    unsigned int size = sizeof(tab) / sizeof(tab[0]);
    unsigned int i;

    printf("Before sorting:\n");
    i = 0;
    while (i < size)
    {
        printf("%d ", tab[i]);
        i++;
    }
    printf("\n");

    sort_int_tab(tab, size);

    printf("After sorting:\n");
    i = 0;
    while (i < size)
    {
        printf("%d ", tab[i]);
        i++;
    }
    printf("\n");

    return 0;
}
