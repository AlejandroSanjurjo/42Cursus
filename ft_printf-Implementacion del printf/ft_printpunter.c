/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpunter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanjurj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:17:58 by asanjurj          #+#    #+#             */
/*   Updated: 2024/10/11 10:01:05 by asanjurj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpunter(void *ptr)
{
	uintptr_t	address;
	int			count;
	int			shift;
	char		*hexa;
	char		buffer[20];

	count = 0;
	if (!ptr)
		return (count += write(1, "(nil)", 5));
	address = (uintptr_t)ptr;
	hexa = "0123456789abcdef";
	buffer[count++] = '0';
	buffer[count++] = 'x';
	shift = (sizeof(uintptr_t) * 8) - 4;
	while (shift >= 0)
	{
		if (hexa[(address >> shift) & 0xF] != '0' || shift == 0 || count > 2)
			buffer[count++] = hexa[(address >> shift) & 0xF];
		shift -= 4;
	}
	write(1, buffer, count);
	return (count);
}
