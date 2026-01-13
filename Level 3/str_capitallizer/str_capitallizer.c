#include <unistd.h>

void	str_capitalize(char *s)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
		{
			new_word = 1;
			write(1, &s[i], 1);
		}
		else
		{
			if (new_word && s[i] >= 'a' && s[i] <= 'z')
				s[i] -= 32;
			else if (!new_word && s[i] >= 'A' && s[i] <= 'Z')
				s[i] += 32;
			new_word = 0;
			write(1, &s[i], 1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		str_capitalize(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}