/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanjurj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:34:04 by asanjurj          #+#    #+#             */
/*   Updated: 2024/10/11 10:08:31 by asanjurj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_comprobar(const char *format, va_list arg);
int	ft_printchar(int c);
int	ft_printstring(char *s);
int	ft_printint(int c);
int	ft_printunsigned(unsigned int c);
int	ft_printhexa(char format, unsigned int c);
int	ft_printpunter(void *ptr);
#endif
