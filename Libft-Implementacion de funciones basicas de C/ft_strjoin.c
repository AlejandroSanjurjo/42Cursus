/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanjurj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:21:48 by asanjurj          #+#    #+#             */
/*   Updated: 2024/09/20 15:11:25 by asanjurj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	p = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!p)
		return (NULL);
	while (i < ft_strlen((char *)s1))
	{
		p[i] = s1[i];
		i++;
	}
	while (j < ft_strlen((char *)s2))
	{
		p[ft_strlen((char *)s1) + j] = s2[j];
		j++;
	}
	p[ft_strlen((char *)s1) + ft_strlen((char *)s2)] = '\0';
	return (p);
}
