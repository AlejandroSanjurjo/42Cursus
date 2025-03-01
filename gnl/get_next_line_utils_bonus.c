/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanjurj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:14:25 by asanjurj          #+#    #+#             */
/*   Updated: 2024/10/03 16:30:55 by asanjurj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	found_new_line(t_list *list)
{
	long long int	i;

	if (!list)
		return (0);
	while (list != NULL)
	{
		i = 0;
		while (list->strbuff[i] && i < BUFFER_SIZE)
		{
			if (list->strbuff[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

t_list	*find_last_node(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	len_to_newlen(t_list *list)
{
	long long int	i;
	long long int	len;

	if (!list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->strbuff[i])
		{
			if (list->strbuff[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

void	copy_str(t_list *list, char *str)
{
	long long int	i;
	long long int	j;

	if (!list)
		return ;
	i = 0;
	while (list)
	{
		j = 0;
		while (list->strbuff[j])
		{
			if (list->strbuff[j] == '\n')
			{
				str[i++] = '\n';
				str[i] = '\0';
				return ;
			}
			str[i++] = list->strbuff[j++];
		}
		list = list->next;
	}
	str[i] = '\0';
}

void	dealloc(t_list **list, t_list *clean_node, char *buff)
{
	t_list	*tmp;

	if (!list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->strbuff);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node && clean_node->strbuff[0])
		*list = clean_node;
	else
	{
		free(buff);
		free(clean_node);
	}
}
