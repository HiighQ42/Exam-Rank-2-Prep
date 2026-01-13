#include <stdlib.h>

static int	ft_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		len;
	long	n;

	n = nbr;
	len = ft_len(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (len-- > 0 && str[len] != '-')
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}