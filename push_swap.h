#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*✅--------------------------------------------------------------*/
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
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
}			t_stack;

/*✅-------------------------push_swap.c--------------------------*/
void		push_swap(char *arg, t_stack *stack_a);
void		push_swap_multi(char **arg, t_stack *stack);

/*✅---------------------push_swap_utils.c------------------------*/
char		*ft_strcpy(char *dst, char *src);
void		ft_putstr(char *s);
void		ft_putchar(int c);
void		swap(int *a, int *b);

/*✅------------------------parser.c------------------------------*/
void		check_digit(char **str);
void		check_digit_multi(char *str);
void		checking_duplicated(t_stack *stack);

/*✅-----------------------swap_rules.c---------------------------*/
void		swap_a(t_stack *stack);
void		swap_b(t_stack *stack);
void		swap_a_and_b(t_stack *stack);

/*✅-----------------------push_rule.c----------------------------*/
void		push_b(t_stack *stack);
void		push_a(t_stack *stack);

/*✅---------------------push_rule_utils.c------------------------*/
void		allocate_temp_free_base_a(t_stack *stack);
void		allocate_temp_free_base_b(t_stack *stack);

/*✅----------------------rotate_rule.c---------------------------*/
void		rotate_a(t_stack *stack);
void		rotate_b(t_stack *stack);
void		rotate_a_b(t_stack *stack);

/*✅--------------------reverse_rotate_rule.c---------------------*/
void		reverse_rotate_a(t_stack *stack);
void		reverse_rotate_b(t_stack *stack);
void		reverse_rotate_a_b(t_stack *stack);

#endif

/*======================================================================*/