#include <unistd.h>

int	main(int argc, char **argv)
{
	int i;
	int end;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	i = 0;
	while (argv[1][i])
		i++;
	i--; // auf letztes Zeichen

	while (i >= 0)
	{
		end = i;
		while (i >= 0 && argv[1][i] != ' ')
			i--;
		write(1, argv[1] + i + 1, end - i);
		if (i > 0)
			write(1, " ", 1);
		i--;
	}
	write(1, "\n", 1);
	return (0);
}