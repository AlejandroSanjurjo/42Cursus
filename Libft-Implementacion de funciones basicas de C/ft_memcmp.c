/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanjurj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:26:20 by asanjurj          #+#    #+#             */
/*   Updated: 2024/09/20 15:16:24 by asanjurj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	unsigned char	*p;
	unsigned char	*s;
	size_t			a;

	s = (unsigned char *)b2;
	p = (unsigned char *)b1;
	a = 0;
	while (a < len)
	{
		if (p[a] != s[a])
			return (p[a] - s[a]);
		a++;
	}
	return (0);
}
