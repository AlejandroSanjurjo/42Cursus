/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanjurj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:05:27 by asanjurj          #+#    #+#             */
/*   Updated: 2024/09/25 12:44:04 by asanjurj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	count_word(char const *s, char set)
{
	int	count;
	int	inword;
	int	i;

	i = 0;
	inword = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != set && inword == 0)
		{
			inword = 1;
			count++;
		}
		else if (s[i] == set)
			inword = 0;
		i++;
	}
	return (count);
}

char	*conserv_word(int start, int end, char const *s)
{
	char	*word;
	int		size;
	int		i;

	i = 0;
	size = end - start;
	word = (char *)malloc(sizeof(char) * (size + 1));
	if (!word)
		return (NULL);
	while (i < size)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**free_memory(char **result, int pos)
{
	while (pos--)
		free(result[pos]);
	free(result);
	return (NULL);
}

char	**ft_aux(char const *s, char c, char **result)
{
	int	i;
	int	start;
	int	pos;

	i = 0;
	pos = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			result[pos] = conserv_word(start, i, s);
			if (!result[pos])
				return (free_memory(result, pos));
			pos++;
		}
		else
			i++;
	}
	result[pos] = '\0';
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	size;

	if (!s)
		return (NULL);
	size = count_word(s, c);
	result = (char **)malloc(sizeof(char *) *(size + 1));
	if (!result)
		return (NULL);
	if (!ft_aux(s, c, result))
		return (NULL);
	return (result);
}
