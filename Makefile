# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 19:05:15 by gabdoush          #+#    #+#              #
#    Updated: 2022/04/08 20:37:31 by gabdoush         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ifndef VERPOSE
#.SILENT:
#endif

NAME = push_swap

FILES = push_swap.c\
		parser.c\
		push_swap_utils.c\
		rules/swap_rule.c\
		rules/push_rule.c\
		rules/push_rule_utils.c\
		rules/rotate_rule.c\
		rules/reverse_rotate_rule.c\
		sort_3_5.c\
		main.c

HEADERS = ./push_swap.h\
		  ./libft/libft.h\

OBJ = $(FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror -g

CC = gcc

all: $(NAME)
$(NAME): $(OBJ)
	@echo "\033[0;31m--------------------------------------------------------------------------------"
	@echo "\033[0;32m 【OK】 ✅\033[0m       \033[0;33m making libft.a:\033[0m" $<
	make -C ./libft
	@echo "\033[0;31m--------------------------------------------------------------------------------"
	@echo "\033[0;32m 【OK】 ✅\033[0m       \033[0;33m Compiling with the flags:\033[0m" $<
	$(CC) -g $(FILES) $(FLAGS) ./libft/libft.a -o push_swap


	@echo "\033[0;31m--------------------------------------------------------------------------------"
	@echo "\033[0;32m 【OK】 ✅\033[0m       \033[0;33m ❮libft.a❯ created:\033[0m" $<
	@echo "\033[0;32m 【OK】 ✅\033[0m       \033[0;33m ❮push_swap❯ compiled:\033[0m" $<
	@echo "\033[0;32m 【OK】 ✅\033[0m       \033[0;33m ❮push_swap❯ created:\033[0m" $<
	@echo "\033[0;31m--------------------------------------------------------------------------------"
clean:
	@echo "\033[0;31m--------------------------------------------------------------------------------"
	make -C ./libft clean
	rm -rf $(OBJ)

	@echo "\033[0;32m 【OK】 ✅\033[0m \033[0;33m ❮Push_Swap❯ objects have been cleaned...\033[0m"
	@echo "\033[0;32m 【OK】 ✅\033[0m \033[0;33m ❮libft❯ objects have been cleaned...\033[0m"
	@echo "\033[0;31m--------------------------------------------------------------------------------"
fclean: clean
	@echo "\033[0;31m--------------------------------------------------------------------------------"
	make -C ./libft fclean
	rm -rf push_swap
	@echo "\033c"
	@echo "\033[0m   【OK】 ✅    \033[0;33m ❮libft archive❯ fcleaned...\033[0m"
	@echo "\033[0m   【OK】 ✅    \033[0;33m ❮Push_Swap excutable❯ fcleaned...\033[0m"
	@echo "\033[0;31m--------------------------------------------------------------------------------"
re: fclean all

.PHONY: all clean fclean re