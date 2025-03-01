/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanjurj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:45:46 by asanjurj          #+#    #+#             */
/*   Updated: 2024/09/24 15:18:45 by asanjurj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*c;
	int		i;

	i = 0;
	c = (char *)malloc(ft_strlen((char *)str) + 1);
	if (!c)
		return (NULL);
	while (str[i])
	{
		c[i] = str[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
