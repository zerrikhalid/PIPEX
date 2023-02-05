# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 22:39:02 by kzerri            #+#    #+#              #
#    Updated: 2023/02/05 02:15:36 by kzerri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
CC			=	cc
CFLAGS		=	-Werror -Wextra -Wall
RM			=	rm -rf
SRCS		=	Mandatory/pipex.c \
				Mandatory/pipex_help.c \
				libft/ft_split.c \
				libft/free_tab.c \
				libft/ft_putendl_fd.c \
				libft/ft_strjoin.c \
				libft/ft_strlen.c \
				libft/ft_strchr.c \
				libft/ft_strncmp.c
SRCS_BONUS	=	Bonus/pipex_bonus.c \
				Bonus/pipex_bonus_help.c \
				libft/ft_split.c \
				libft/free_tab.c \
				libft/ft_putendl_fd.c \
				libft/ft_putstr_fd.c \
				libft/ft_strjoin.c \
				libft/ft_strlen.c \
				libft/ft_strchr.c \
				libft/ft_strncmp.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \
				
OBJS		= $(SRCS:.c=.o)

OBJS_BONUS	= $(SRCS_BONUS:.c=.o) 

$(NAME)		: $(SRCS) $(Mandatory/pipex.h)
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	
all			:	$(NAME)

clean		:
			$(RM) $(OBJS) $(OBJS_BONUS) $(NAME)

fclean		: clean
			$(RM) $(NAME)

re			: fclean all

bonus 		: $(SRCS_BONUS) $(Bonus/pipex_bonus.h)
			$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME)
