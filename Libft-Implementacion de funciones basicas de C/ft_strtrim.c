/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanjurj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:32:37 by asanjurj          #+#    #+#             */
/*   Updated: 2024/09/24 16:05:30 by asanjurj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	isinstring(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*result;

	start = 0;
	i = 0;
	end = ft_strlen(s1);
	while (s1[start] && isinstring(s1[start], set))
		start++;
	while (end > start && isinstring(s1[end - 1], set))
		end--;
	result = (char *)malloc(end - start + 1);
	if (!result)
		return (NULL);
	while (i < end - start)
	{
		result[i] = s1[start + i];
		i++;
	}
	result[end - start] = '\0';
	return (result);
}
