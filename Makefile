# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/11 20:08:10 by hyyang            #+#    #+#              #
#    Updated: 2021/04/11 20:59:28 by hyyang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c \
				#sources/ft_sample.c
			
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
	$(CC) $(CFLAGS) -c $< $(INCLUEDS)

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
