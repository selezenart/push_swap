# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aselezen <aselezen@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/17 12:38:00 by aselezen          #+#    #+#              #
#    Updated: 2026/06/18 01:15:32 by aselezen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CHECKER		= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

COMMON_SRCS	= parse.c parse_check.c stack_utils.c utils.c \
			  swap_ops.c push_ops.c rotate_ops.c reverse_rotate_ops.c

PS_SRCS		= push_swap.c flags.c solver.c bench.c \
			  simple_sort.c sort_five.c medium_sort.c complex_sort.c $(COMMON_SRCS)

CH_SRCS		= checker_bonus.c checker_utils_bonus.c $(COMMON_SRCS)

PS_OBJS		= $(PS_SRCS:.c=.o)
CH_OBJS		= $(CH_SRCS:.c=.o)

all: $(NAME)

bonus: $(CHECKER)

$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR)

FORCE:

$(NAME): $(LIBFT) $(PS_OBJS)
	$(CC) $(CFLAGS) $(PS_OBJS) $(LIBFT) -o $(NAME)

$(CHECKER): $(LIBFT) $(CH_OBJS)
	$(CC) $(CFLAGS) $(CH_OBJS) $(LIBFT) -o $(CHECKER)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

checker_bonus.o checker_utils_bonus.o: checker_bonus.h

clean:
	$(RM) $(PS_OBJS) $(CH_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(CHECKER)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re FORCE
