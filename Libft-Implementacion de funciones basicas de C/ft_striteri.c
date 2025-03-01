/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanjurj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:37:04 by asanjurj          #+#    #+#             */
/*   Updated: 2024/09/19 14:06:15 by asanjurj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	n;
	unsigned int	i;

	n = ft_strlen(s);
	i = 0;
	while (i < n)
	{
		f(i, &s[i]);
		i++;
	}
}
