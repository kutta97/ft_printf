# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/11 20:08:10 by hyyang            #+#    #+#              #
#    Updated: 2021/04/11 22:13:21 by hyyang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR	= sources/
SRCS_LST	= ft_putchar.c
SRCS		= ft_printf.c \
				$(addprefix $(SRCS_DIR), $(SRCS_LST))

OBJS		= $(SRCS:%.c=%.o)

AR			= ar -crs
CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror
INCLUEDS	= -I./includes

NAME		= libftprintf.a

LIBFT		= libft
LIBFT_LIB	= $(LIBFT).a
LIBFT_DIR	= ./$(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUEDS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) all -C $(LIBFT_DIR)
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
