# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asanjurj <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 12:28:47 by asanjurj          #+#    #+#              #
#    Updated: 2024/10/11 09:29:39 by asanjurj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SOURCE = ft_itoa.c ft_printchar.c ft_printexa.c ft_printf.c ft_printnumb.c\
ft_printpunter.c



OBJ = $(SOURCE:.c=.o)
INCLUDE = ft_printf.h libft.h

BONUSOBJ = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
		$(LIB) $(NAME) $(OBJ)
bonus: $(BONUSOBJ) $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(BONUSOBJ) $(OBJ)


clean:
	$(RM) $(OBJ) $(BONUSOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus
.PHONY: all fclean re clean bonus
