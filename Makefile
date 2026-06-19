# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/17 12:38:00 by aselezen          #+#    #+#              #
#    Updated: 2026/06/19 13:07:12 by aselezen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
FLAGS = -Wall -Wextra -Werror

SHARED_SRC = parse.c \
			parse_check.c \
			stack_utils.c \
			utils.c \
			push_ops.c \
			swap_ops.c \
			rotate_ops.c \
			reverse_rotate_ops.c

SRC = push_swap.c \
			$(SHARED_SRC) \
			solver.c \
			flags.c \
			bench.c \
			simple_sort.c \
			medium_sort.c \
			complex_sort.c \
			sort_five.c

BONUS_SRC = checker_bonus.c \
			checker_utils_bonus.c \
			$(SHARED_SRC)

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)
	@echo "libft archive created successfully!"

%.o: %.c
	@$(CC) $(FLAGS) -I . -I $(LIBFT_DIR) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "push_swap compiled successfully!"

bonus: $(LIBFT) $(BONUS_OBJ)
	@$(CC) $(FLAGS) $(BONUS_OBJ) $(LIBFT) -o $(BONUS_NAME)
	@echo "bonus checker compiled successfully!"

clean:
	@rm -f $(OBJ)
	@rm -f $(BONUS_OBJ)
	@echo "removed object files."

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
	@echo "deleted push_swap and / or checker."
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@echo "deleted libft archive."

re: fclean all

.PHONY: all bonus clean fclean re
