/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanjurj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:52:02 by asanjurj          #+#    #+#             */
/*   Updated: 2024/10/11 10:05:09 by asanjurj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	int	count;

	count = 0;
	write(1, &c, 1);
	return (++count);
}

int	ft_printstring(char *c)
{
	int	count;

	count = 0;
	if (!c)
		return (count += write(1, "(null)", 6));
	while (*c)
	{
		write(1, c, 1);
		count++;
		c++;
	}
	return (count);
}
