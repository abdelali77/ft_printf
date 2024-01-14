# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 12:10:22 by abmahfou          #+#    #+#              #
#    Updated: 2024/01/12 18:21:32 by abmahfou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
	  ft_print_str.c \
	  ft_print_dec_hex.c \
	  ft_print_addr.c \
	  ft_print_unsigned.c \
	  ft_print_char.c 

CC = cc

CFLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all