#include <unistd.h>

int	ft_atoi(char *str)
{
	int	res = 0;

	while (*str)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}

void	print_hex(int n)
{
	char	*base = "0123456789abcdef";

	if (n >= 16)
		print_hex(n / 16);
	write(1, &base[n % 16], 1);
}

int	main(int argc, char **argv)
{
	int	n;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	n = ft_atoi(argv[1]);
	print_hex(n);
	write(1, "\n", 1);
	return (0);
}