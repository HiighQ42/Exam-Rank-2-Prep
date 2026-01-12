int	ft_atoi_base(const char *str, int str_base)
{
	char	*number;
	int		result;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	number = (char *)str;
	if (number[i] == '-')
	{
		sign *= -1;
		i++;
	}
	result = 0;
	while (number[i] != '\0')
	{
		if (number[i] >= '0' && number[i] <= '9')
			result = result * str_base + number[i] - '0';
		else if (number[i] >= 'A' && number[i] <= 'F')
			result = result * str_base + number[i] - '7';
		else if (number[i] >= 'a' && number[i] <= 'f')
			result = result * str_base + number[i] - 'W';
		i++;
	}
	return (sign * result);
}
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi_base("500", 2));
	return (0);
}