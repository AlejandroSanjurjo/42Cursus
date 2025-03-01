/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanjurj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 08:54:35 by asanjurj          #+#    #+#             */
/*   Updated: 2024/09/25 13:13:08 by asanjurj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	void	*aux;

	if (!lst || !f)
		return (NULL);
	aux = f(lst->content);
	if (!aux)
		return (NULL);
	list = ft_lstnew(aux);
	if (!list)
	{
		del(aux);
		return (NULL);
	}
	if (lst->next)
	{
		list->next = ft_lstmap(lst->next, f, del);
		if (!list->next)
		{
			ft_lstdelone(list, del);
			return (NULL);
		}
	}
	return (list);
}
