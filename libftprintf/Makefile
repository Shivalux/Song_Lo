# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/27 18:38:37 by sharnvon          #+#    #+#              #
#    Updated: 2022/06/29 22:22:46 by sharnvon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_util1.c ft_printf_util2.c ft_printf_preprint.c ft_printf_printer.c
OBJS = $(SRCS:.c=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	@ar -crs $(NAME) $(OBJS)

bonus : $(NAME)
	@ar -crs $(NAME) $(OBJS)

norminette : 
	@norminette -R CheckForbbidenHeaderSource $(SRCS)
	@norminette -R CheckDehfine libftprintf.h
	
clean: 
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all bonus

.PHONY: re fclean clean all bonus
