#ifndef PUSH_SWAP
# define PUSH_SWAP

/*--------------------------------------------------------------*/
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
/*--------------------------------------------------------------*/
# include "./libft/libft.h"

typedef struct s_stacks
{
	int		*base_a;
	int		*base_b;
	
	int		num;
	
	int		len_a;
	int		len_b;

	int		*temp_a;
	int		*temp_b;

	int		len_temp_a;
	int		len_temp_b;
}			t_stack;

/*-------------------------push_swap.c--------------------------*/
void		push_swap(char *arg, t_stack *stack_a);
/*---------------------push_swap_utils.c------------------------*/
char		*ft_strcpy(char *dst, char *src);
void		ft_putstr(char *s);
void		ft_putchar(int c);
void		swap(int *a, int *b);
/*-------------------------Parser.c-----------------------------*/
void		check_digit(char **str);
void		checking_duplicated(t_stack *stack);
/*-------------------------Rules.c------------------------------*/
// void		swap_a(t_stack stack);
// void		swap_b(t_stack stack_b);
// void		swap_a_and_b(t_stack  stack_a, t_stack stack_b);
void		push_b(t_stack *stack);
/*--------------------------------------------------------------*/

#endif
