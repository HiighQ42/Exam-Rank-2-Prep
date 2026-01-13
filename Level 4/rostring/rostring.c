#include <unistd.h>

void	putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int	main(int argc, char **argv)
{
	int i = 0;
	int start;
	int first_len;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	/* skip leading spaces/tabs */
	while (argv[1][i] == ' ' || argv[1][i] == '\t')
		i++;

	start = i;

	/* find first word length */
	while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
		i++;
	first_len = i - start;

	/* print remaining words */
	while (argv[1][i])
	{
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		if (argv[1][i])
		{
			putstr(&argv[1][i]);
			while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
				i++;
			write(1, " ", 1);
		}
	}

	/* print first word */
	write(1, &argv[1][start], first_len);
	write(1, "\n", 1);

	return (0);
}