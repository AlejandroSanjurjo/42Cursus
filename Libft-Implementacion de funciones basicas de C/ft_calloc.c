/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanjurj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:28:36 by asanjurj          #+#    #+#             */
/*   Updated: 2024/09/19 12:37:11 by asanjurj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*mem;

	mem = malloc (number * size);
	if (!mem)
		return (NULL);
	ft_bzero (mem, (number * size));
	return (mem);
}
