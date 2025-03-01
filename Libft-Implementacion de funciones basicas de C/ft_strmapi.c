/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanjurj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:17:52 by asanjurj          #+#    #+#             */
/*   Updated: 2024/09/25 09:54:53 by asanjurj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	int		n;
	int		i;

	if (!s)
		return (NULL);
	n = ft_strlen((char *)s);
	i = 0;
	p = (char *)malloc(n + 1);
	if (!p)
		return (NULL);
	while (i < n)
	{
		p[i] = f(i, s[i]);
		i++;
	}
	p[n] = '\0';
	return (p);
}
