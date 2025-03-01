/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanjurj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 08:52:40 by asanjurj          #+#    #+#             */
/*   Updated: 2024/09/24 18:24:49 by asanjurj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *str1, char *str2, size_t n)
{
	size_t	a;

	a = 0;
	if (n == 0)
		return (0);
	while (str1[a] == str2[a] && a < n && str1[a] != '\0' && str2[a] != '\0')
		a++;
	if (a == n)
		return (0);
	return ((unsigned char)str1[a] - (unsigned char)str2[a]);
}
