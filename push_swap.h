#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*✅--------------------------------------------------------------------------*/
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int		*base_a;
	int		*base_b;

	int		num;
	int		rules_number;

	int		len_a;
	int		len_b;

	int		*temp_a;
	int		*temp_b;
}			t_stack;

typedef struct save_s
{
	int		m;
	int		k;
}			save_t;

/*✅-------------------------------push_swap.c--------------------------------*/
void		push_swap(char *arg, t_stack *stack_a, save_t *save);
void		push_swap_multi(char **arg, t_stack *stack, int i, save_t *save);

/*✅---------------------------push_swap_utils.c------------------------------*/
char		*ft_strcpy(char *dst, char *src);
void		ft_putstr(char *s);
void		ft_putchar(int c);
void		swap(int *a, int *b);
void		error(void);
void		addLast(t_stack *stack, int num);
int			is_sorted(t_stack *stack);

/*✅------------------------------parser.c------------------------------------*/
void		check_digit(char **str);
void		check_digit_multi(char *str);
void		check_negative_sign(char *str);
void		checking_duplicated(t_stack *stack);
void		check_empty(char *arg);

/*✅-----------------------------swap_rules.c---------------------------------*/
void		swap_a(t_stack *stack);
void		swap_b(t_stack *stack);
void		swap_a_and_b(t_stack *stack);

/*✅-----------------------------push_rule.c----------------------------------*/
void		push_b(t_stack *stack);
void		push_a(t_stack *stack);

/*✅---------------------------push_rule_utils.c------------------------------*/
void		allocate_temp_free_base_a(t_stack *stack);
void		allocate_temp_free_base_b(t_stack *stack);

/*✅----------------------------rotate_rule.c---------------------------------*/
void		rotate_a(t_stack *stack);
void		rotate_b(t_stack *stack);
void		rotate_a_b(t_stack *stack);

/*✅--------------------------reverse_rotate_rule.c---------------------------*/
void		reverse_rotate_a(t_stack *stack);
void		reverse_rotate_b(t_stack *stack);
void		reverse_rotate_a_b(t_stack *stack);

/*✅-------------------------------sort_3_4_5.c-------------------------------*/
void		sort_2(t_stack *stack);
void		sort_3(t_stack *stack);
void		sort_4(t_stack *stack);
void		sort_5(t_stack *stack);

/*✅----------------------------sort_3_4_5_utils.c----------------------------*/
int			get_smallest_position(t_stack *stack, int smallest_num);
int			get_smallest(t_stack *stack);


long long	convert(int n);
void		positive_sort(t_stack *stack, save_t *save);

#endif

/*============================================================================*/