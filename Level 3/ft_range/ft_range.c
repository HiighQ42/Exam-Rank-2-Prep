#include <stdio.h>
#include <stdlib.h>
int     *ft_range(int start, int end)
{
    int len = end - start;
    if (len < 0)
        len = -len;
    len += 1;

    int *result = (int *)malloc(sizeof(int) * len);
    int i = 0;

    if (!result)
        return NULL;

    while (i < len)
    {
        result[i] = start;
        if (start < end)
            start++;
        else
            start--;
        i++;
    }
    return result;
}
void	print_range(int *arr, int start, int end)
{
	int	len;
	int	i;

	len = abs(end - start) + 1;
	i = 0;
	while (i < len)
	{
		printf("%d", arr[i]);
		if (i < len - 1)
			printf(", ");
		i++;
	}
	printf("\n");
}

int	main(void)
{
	int	*arr;

	arr = ft_range(1, 3);
	print_range(arr, 1, 3);
	free(arr);

	arr = ft_range(-1, 2);
	print_range(arr, -1, 2);
	free(arr);

	arr = ft_range(0, 0);
	print_range(arr, 0, 0);
	free(arr);

	arr = ft_range(0, -3);
	print_range(arr, 0, -3);
	free(arr);

	return (0);
}