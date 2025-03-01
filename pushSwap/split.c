#include "push_swap.h"

static int	count_words(char *str, char c)
{
	int		count;
	bool	flag;

	count = 0;
	while (*str)
	{
		flag = false;
		while (*str == c && *str)
			++str;
		while (*str != c && *str)
		{
			if (!flag)
			{
				++count;
				flag = true;
			}
			++str;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char c)
{
	static int	cursor = 0;
	char		*word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == c)
		++cursor;
	while ((str[cursor + len] != c) && str[cursor + len])
		++len;
	word = malloc((size_t)len * sizeof(char) + 1);
	if (NULL == word)
		return (NULL);
	while ((str[cursor] != c) && str[cursor])
		word[i++] = str[cursor++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char c)
{
	int		words;
	char	**vector_strings;
	int		i;

	i = 0;
	words = count_words(str, c);
	if (!words)
		exit(1);
	vector_strings = malloc(sizeof(char *) * (size_t)(words + 2));
	if (NULL == vector_strings)
		return (NULL);
	while (words-- >= 0)
	{
		if (0 == i)
		{
			vector_strings[i] = malloc(sizeof(char));
			if (NULL == vector_strings[i])
				return (NULL);
			vector_strings[i++][0] = '\0';
			continue ;
		}
		vector_strings[i++] = get_next_word(str, c);
	}
	vector_strings[i] = NULL;
	return (vector_strings);
}
