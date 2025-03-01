/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanjurj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 08:53:10 by asanjurj          #+#    #+#             */
/*   Updated: 2024/09/24 18:09:14 by asanjurj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	uc;
	int				a;

	uc = (unsigned char)c;
	a = ft_strlen((char *)s);
	while (a >= 0)
	{
		if ((unsigned char )s[a] == uc)
			return ((char *)&s[a]);
		a--;
	}
	return (NULL);
}
