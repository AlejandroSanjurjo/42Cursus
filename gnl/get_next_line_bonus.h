/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanjurj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:19:10 by asanjurj          #+#    #+#             */
/*   Updated: 2024/10/03 16:33:42 by asanjurj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4294967295
# endif

# ifndef MAX_FD
#  define MAX_FD 60000
# endif

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_list
{
	char			*strbuff;
	struct s_list	*next;
}			t_list;

int		found_new_line(t_list *list);
t_list	*find_last_node(t_list *list);
int		len_to_newlen(t_list *list);
void	copy_str(t_list *list, char *str);
void	dealloc(t_list **list, t_list *clean_node, char *buff);
void	polish_list(t_list **list);
void	append(t_list **list, char *buf);
char	*get_line1(t_list *list);
void	create_list(t_list **list, int fd);
char	*get_next_line(int fd);
#endif
