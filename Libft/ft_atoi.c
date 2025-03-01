/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanjurj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:07:24 by asanjurj          #+#    #+#             */
/*   Updated: 2024/09/24 15:16:46 by asanjurj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	a;
	int	neg;
	int	num;

	num = 0;
	a = 0;
	neg = 1;
	while (nptr[a] == ' ' || (nptr[a] >= 9 && nptr[a] <= 13))
		a++;
	if (nptr[a] == '-')
	{
		neg = -1;
		a++;
	}
	else if (nptr[a] == '+')
		a++;
	if ((nptr[a] < '0' || '9' < nptr[a]))
		return (num);
	while ((nptr[a] >= '0' && '9' >= nptr[a]) && nptr[a])
	{
		num = num * 10 + (nptr[a] - '0');
		a++;
	}
	return (num * neg);
}
