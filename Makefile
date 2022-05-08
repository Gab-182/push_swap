# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 16:15:35 by gabdoush          #+#    #+#              #
#    Updated: 2022/05/08 15:30:29 by gabdoush         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ifndef VERPOSE
# .SILENT:
# endif


NAME = push_swap

FILES = push_swap.c\
		errors.c\
		free_args.c\
		parser.c\
		push_swap_utils.c\
		rules/oper_1.c\
		rules/oper_2.c\
		rules/oper_3.c\
		sort/sort_chunk_3_b.c\
		sort/sort_chunk_5_b.c\
		sort/stack_b.c\
		sort/stack_a.c\
		sort/sort_chunk_3_a.c\
		sort/sort_chunk_5_a.c\
		sort/small_sorting_a_4.c\
		sort/small_sorting_a_5.c\
		sort/sort_utils.c\
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