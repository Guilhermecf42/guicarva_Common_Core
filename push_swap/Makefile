# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfranca <gfranca@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/20 11:20:54 by guicarva          #+#    #+#              #
#    Updated: 2026/06/24 17:28:24 by gfranca          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = push_swap
BONUS    = checker
CC       = cc
CFLAGS   = -Wall -Werror -Wextra -g
MKDIR    = mkdir -p

SRCS_DIR = srcs
OBJS_DIR = objs
INCS_DIR = includes

RM = rm -rf

COMMON_SRCS = \
		$(SRCS_DIR)/free_and_check.c \
		$(SRCS_DIR)/ft_printf_utils.c \
		$(SRCS_DIR)/ft_printf.c \
		$(SRCS_DIR)/ft_split.c \
		$(SRCS_DIR)/get_next_line_utils.c \
		$(SRCS_DIR)/make_stack.c \
		$(SRCS_DIR)/o_push.c \
		$(SRCS_DIR)/o_rotate_r.c \
		$(SRCS_DIR)/o_rotate.c \
		$(SRCS_DIR)/o_swap.c \
		$(SRCS_DIR)/sort_k.c \
		$(SRCS_DIR)/sort_radix.c \
		$(SRCS_DIR)/sort_simple.c \
		$(SRCS_DIR)/sort_turk_utils.c \
		$(SRCS_DIR)/sort_turk.c \
		$(SRCS_DIR)/stack_utils.c

PUSH_SWAP_SRCS = $(COMMON_SRCS) $(SRCS_DIR)/push_swap.c
CHECKER_SRCS   = $(COMMON_SRCS) $(SRCS_DIR)/checker.c


PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
CHECKER_OBJS   = $(CHECKER_SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJS) -o $@

bonus: $(BONUS)

$(BONUS): $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(MKDIR) $(OBJS_DIR)
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)
	
fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
