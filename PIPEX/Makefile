# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 22:39:02 by kzerri            #+#    #+#              #
#    Updated: 2023/01/23 03:45:11 by kzerri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
CC			=	cc
CFLAGS		=	-Werror -Wextra -Wall
RM			=	rm -rf
SRCS		=	Mandatory/pipex.c \
				Mandatory/pipex_help.c \
				libft/ft_split.c \
				libft/ft_putendl_fd.c \
				libft/ft_strjoin.c \
				libft/ft_strlen.c \
				libft/ft_strchr.c \
				libft/ft_strnstr.c
SRCS_BONUS	= 
OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

$(NAME)		: $(SRCS)
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all			:	$(NAME)

clean		:
			$(RM) $(OBJS) $(OBJS_BONUS) $(NAME)

fclean		: clean
			$(RM) $(NAME)

re			: fclean all

bonus 		: $(SRCS_BONUS)
			$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME)