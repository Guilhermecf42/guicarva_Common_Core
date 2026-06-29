# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/20 11:20:54 by guicarva          #+#    #+#              #
#    Updated: 2026/05/17 14:26:17 by guicarva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

AR = ar rcs

RM = rm -f

SRCS = \
		ft_printf.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_putnbr_hexa.c \
		ft_putnbr_unsigned.c \
		ft_putnbr_pointer.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)

test: all
	$(CC) $(CFLAGS) main.c $(NAME) ;./a.out

valgrind: a.out
	valgrind --leak-check=full --show-leak-kinds=all ./a.out;rm a.out
	
re: fclean all

.PHONY: all clean fclean re test valgrind
