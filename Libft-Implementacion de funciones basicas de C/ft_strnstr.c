/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanjurj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:33:45 by asanjurj          #+#    #+#             */
/*   Updated: 2024/09/24 14:48:23 by asanjurj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	if (*little == '\0' || little == NULL)
		return ((char *)big);
	while (big[a] && a < len)
	{
		b = 0;
		while (big[a + b] == little[b] && a + b < len)
		{
			if (little[b + 1] == '\0')
				return ((char *)big + a);
			b++;
		}
		a++;
	}
	return (NULL);
}
