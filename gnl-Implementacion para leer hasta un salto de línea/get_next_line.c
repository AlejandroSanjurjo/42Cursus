/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanjurj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:33:33 by asanjurj          #+#    #+#             */
/*   Updated: 2024/10/03 15:02:10 by asanjurj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	polish_list(t_list **list)
{
	t_list				*last_node;
	t_list				*clean_node;
	long long int		i;
	long long int		j;
	char				*buff;

	if (!list)
		return ;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	clean_node = malloc(sizeof(t_list));
	if (!clean_node || !buff)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	j = 0;
	while (last_node->strbuff[i] != '\n' && last_node->strbuff[i])
		i++;
	while (last_node->strbuff[i] && last_node->strbuff[++i])
		buff[j++] = last_node->strbuff[i];
	buff[j] = '\0';
	clean_node->strbuff = buff;
	clean_node->next = NULL;
	dealloc(list, clean_node, buff);
}

void	append(t_list **list, char *buff)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (!last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->strbuff = buff;
	new_node->next = NULL;
}

char	*get_line1(t_list *list)
{
	long long int		leng;
	char				*new_line;

	if (!list)
		return (NULL);
	leng = len_to_newlen (list);
	new_line = (char *)malloc(sizeof(char) * (leng + 1));
	if (!new_line)
		return (NULL);
	copy_str(list, new_line);
	return (new_line);
}

void	create_list(t_list **list, int fd)
{
	long long int		byterd;
	char				*buff;

	while (!found_new_line(*list))
	{
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return ;
		byterd = read(fd, buff, BUFFER_SIZE);
		if (byterd <= 0)
		{
			free(buff);
			if (byterd < 0)
				dealloc(list, NULL, NULL);
			return ;
		}
		buff[byterd] = '\0';
		append(list, buff);
	}
}

char	*get_next_line(int fd)
{
	char			*next_line;
	static t_list	*list = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(0, &next_line, 0) < 0)
	{
		dealloc(&list, NULL, NULL);
		return (NULL);
	}
	create_list(&list, fd);
	if (!list)
		return (NULL);
	next_line = get_line1(list);
	polish_list(&list);
	return (next_line);
}
