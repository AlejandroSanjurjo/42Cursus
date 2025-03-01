/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanjurj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:00:55 by asanjurj          #+#    #+#             */
/*   Updated: 2024/09/20 15:17:25 by asanjurj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	size_t			a;
	unsigned char	*s;

	a = 0;
	s = (unsigned char *)b;
	while (a < len)
	{
		if (s[a] == (unsigned char)c)
			return ((void *)&s[a]);
		a++;
	}
	return (NULL);
}
