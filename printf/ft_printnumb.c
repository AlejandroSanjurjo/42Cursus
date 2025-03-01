/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanjurj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:49:07 by asanjurj          #+#    #+#             */
/*   Updated: 2024/10/11 10:35:03 by asanjurj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_itoa(int c);

static int	count_digits(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	minint(void)
{
	int	count;

	write(1, "-2147483648", 11);
	return (count = 11);
}

int	ft_printint(int c)
{
	int		count;
	char	*numb;
	char	*tmp;

	count = 0;
	if (c == -2147483648)
		return (minint());
	if (c < 0)
	{
		write(1, "-", 1);
		count++;
		c *= -1;
	}
	numb = ft_itoa(c);
	tmp = numb;
	while (*numb)
	{
		write(1, numb, 1);
		count++;
		numb++;
	}
	free(tmp);
	return (count);
}

int	ft_printunsigned(unsigned int c)
{
	int		aux;
	char	*result;
	int		count;

	count = count_digits(c);
	aux = count;
	result = (char *)malloc(count + 1);
	if (!result)
		return (0);
	result[aux] = '\0';
	if (c == 0)
		result[0] = '0';
	while (c > 0)
	{
		result[--aux] = (c % 10) + '0';
		c /= 10;
	}
	write(1, result, count);
	free(result);
	return (count);
}
