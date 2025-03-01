/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanjurj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:57:03 by asanjurj          #+#    #+#             */
/*   Updated: 2024/10/11 10:15:05 by asanjurj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexa(char format, unsigned int c)
{
	char	*uphexa;
	char	*lowhexa;
	int		count;

	uphexa = "0123456789ABCDEF";
	lowhexa = "0123456789abcdef";
	count = 0;
	if (c > 15)
		count += ft_printhexa(format, c / 16);
	if (format == 'X')
		write(1, &uphexa[c % 16], 1);
	else
		write(1, &lowhexa[c % 16], 1);
	count ++;
	return (count);
}
