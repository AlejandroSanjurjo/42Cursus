/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanjurj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:06:45 by asanjurj          #+#    #+#             */
/*   Updated: 2024/09/24 13:31:47 by asanjurj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char	*s;
	size_t			a;

	a = 0;
	s = dest;
	while (a < len)
	{
		s[a] = (unsigned char) c;
		a++;
	}
	return (dest);
}
