# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 23:33:53 by machaiba          #+#    #+#              #
#    Updated: 2023/01/06 00:31:43 by machaiba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = pipex.c\
		ft_split.c\
		ft_strlen.c\
		ft_substr.c\
		ft_strdup.c\
		cmdcheck.c\
		cmdcheck2.c\
		get_path.c\
		ft_strjoin.c\

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
clean : 
		rm -rf $(OBJ)

fclean : clean
		rm -rf $(NAME)

re : fclean all