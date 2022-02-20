# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 11:05:39 by gabdoush          #+#    #+#              #
#    Updated: 2022/02/20 14:59:58 by gabdoush         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES =  ft_atoi\
	 ft_isalnum\
	 ft_isalpha\
	 ft_isascii\
	 ft_isdigit\
	 ft_isprint\
	 ft_itoa\
	 ft_tolower\
	 ft_toupper\
	 ft_bzero\
	 ft_calloc\
	 ft_memcmp\
	 ft_memset\
	 ft_memcpy\
	 ft_memmove\
	 ft_memchr\
	 ft_split\
	 ft_strncmp\
	 ft_putchar_fd\
	 ft_putstr_fd\
	 ft_putendl_fd\
	 ft_putnbr_fd\
	 ft_substr\
	 ft_striteri\
	 ft_strdup\
	 ft_lstnew\
	 ft_lstadd_front\
	 ft_lstsize\
	 ft_lstlast\
	 ft_lstadd_back\
	 ft_lstdelone\
	 ft_lstclear\
	 ft_lstiter\
	 ft_lstmap\
	 ft_strlen\
	 ft_strlcpy\
	 ft_strcmp

OBJECTS =	$(FILES:.c=.o)

HEADERS = libft.h 

FLAGS = -Wall -Werror -Wextra

CC = gcc -c

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc libft.a $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -rf  $(NAME)

re: fclean all

.PHONY:	all clean fclean re
