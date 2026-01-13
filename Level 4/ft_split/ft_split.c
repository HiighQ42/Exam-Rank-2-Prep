#include <stdlib.h>

static int	is_sep(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int	count_words(char *str)
{
	int	count = 0;
	int	in_word = 0;

	while (*str)
	{
		if (!is_sep(*str) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_sep(*str))
			in_word = 0;
		str++;
	}
	return (count);
}

static char	*word_dup(char *str)
{
	int		len = 0;
	char	*word;
	int		i = 0;

	while (str[len] && !is_sep(str[len]))
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**result;
	int		i = 0;

	result = malloc(sizeof(char *) * (count_words(str) + 1));
	if (!result)
		return (NULL);
	while (*str)
	{
		if (!is_sep(*str))
		{
			result[i++] = word_dup(str);
			while (*str && !is_sep(*str))
				str++;
		}
		else
			str++;
	}
	result[i] = NULL;
	return (result);
}