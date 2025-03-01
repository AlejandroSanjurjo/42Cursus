/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanjurj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:07:31 by asanjurj          #+#    #+#             */
/*   Updated: 2024/10/11 09:59:59 by asanjurj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_comprobar(const char *format, va_list arg)
{
	if (*format == 'd')
		return (ft_printint(va_arg(arg, int)));
	if (*format == 'c')
		return (ft_printchar(va_arg(arg, int)));
	if (*format == 's')
		return (ft_printstring(va_arg(arg, char *)));
	if (*format == 'u')
		return (ft_printunsigned(va_arg(arg, unsigned int )));
	if (*format == 'x' || *format == 'X')
		return (ft_printhexa(*format, va_arg (arg, int)));
	if (*format == 'p')
		return (ft_printpunter(va_arg(arg, void *)));
	if (*format == '%')
		return (ft_printchar('%'));
	if (*format == 'i')
		return (ft_printint(va_arg(arg, int)));
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;

	va_start(arg, format);
	count = 0;
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			format++;
			count++;
		}
		else
		{
			count += ft_comprobar(++format, arg);
			format++;
		}
	}
	va_end(arg);
	return (count);
}
