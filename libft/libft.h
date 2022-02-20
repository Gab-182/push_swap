/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:05:29 by gabdoush          #+#    #+#             */
/*   Updated: 2022/02/21 01:56:37 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../push_swap.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

int				ft_atoi(char *str);
int				ft_isalnum(int n);
int				ft_isalpha(int n);
int				ft_isascii(int n);
int				ft_isdigit(int n);
int				ft_isprint(int n);
int				ft_tolower(int n);
int				ft_toupper(int n);
void			ft_bzero(void *dest, size_t len);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_memcmp(const void *s1, const void *s2, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *dest, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *b, int c, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t len);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			**ft_split(char *s, char c);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strdup(char *s1);
int				ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strjoin(char *s1, char *s2);
/*---------------------------The Bonus part--------------------------------*/

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

#endif
