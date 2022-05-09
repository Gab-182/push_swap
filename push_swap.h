/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:19:36 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/10 03:48:51 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
/*✅---------------------------  Structure  --------------------------------*/
/*********** Stack struct********/
typedef struct s_stack
{
	int		*base_a;
	int		*base_b;

	int		num;
	int		rules_number;
	int		middle_num;

	int		len_a;
	int		len_b;

	int		*temp_a;
	int		*temp_b;
}			t_stack;
/*********************************/

/***********  Rules struct********/
typedef struct s_rules
{
	long	piv_big;
	long	piv_small;
	int		ra;
	int		rb;
	int		pa;
	int		pb;
}			t_rules;
/*********************************/

/*✅-------------------------------push_swap.c------------------------------*/

void		sort(int size, t_stack *stack);
void		push_swap(char *arg, t_stack *stack_a);
void		push_swap_multi(char **arg, t_stack *stack);

/*✅---------------------------push_swap_utils.c----------------------------*/

void		ft_stack_cpy(int *dst, int *src, int size);
void		add_last(t_stack *stack, int num);
int			is_sorted(t_stack *stack);

/*✅------------------------------errors.c----------------------------------*/

void		error_with_free_2d(char **str);
void		error(void);
void		free_stack(int *stack, char flag);
void		error_with_free_1d(char *str);

/*✅----------------------------free_args.c----------------------------------*/

void		free_exit(char **str);
void		free_2d(char **str);

/*✅------------------------------parser.c------------------------------------*/

void		check_digit(char **str);
void		check_digit_multi(char *str);
void		check_negative_sign(char **str);
void		checking_duplicated(t_stack *stack);
void		check_empty(char *arg);

/*✅-------------------------------oper_1.c----------------------------------*/

int			*push(int *stack, int element, int *old_stack, int size);
int			*new_stack(int *stack, int size);
void		push_b(t_stack *stack);
void		push_a(t_stack *stack);

/*✅-------------------------------oper_2.c----------------------------------*/

void		rotate(int *tab, int size);
void		reverse_rotate(int *tab, int size);
void		rotate_a(t_stack *stack);
void		rotate_b(t_stack *stack);
void		reverse_rotate_a(t_stack *stack);
void		reverse_rotate_b(t_stack *stack);
void		rotate_a_b(t_stack *stack);
void		reverse_rotate_a_b(t_stack *stack);

/*✅-------------------------------oper_3.c----------------------------------*/

void		swap_a(t_stack *stack);
void		swap_b(t_stack *stack);

/*✅------------------------------sort_chunk_3_a.c---------------------------*/

void		sort_2_a(t_stack *stack);
void		sort_chunk_3_a(int size, t_stack *stack);

/*✅------------------------------sort_chunk_5_a.c---------------------------*/

void		sort_chunk_5_a(int size, t_stack *stack);

/*✅------------------------------sort_chunk_3_b.c---------------------------*/

void		sort_chunk_3_b(int size, t_stack *stack);
void		sort_2_b(t_stack *stack);

/*✅------------------------------sort_chunk_5_b.c---------------------------*/

void		sort_chunk_5_b(int size, t_stack *stack);
void		bubble_sort_5(int *chunk);
int			get_middle_num_five_b(t_stack *stack);

/*✅---------------------------small_sorting_a_4.c---------------------------*/

void		sort_4_a(int size, t_stack *stack);

/*✅---------------------------small_sorting_a_5.c---------------------------*/

void		sort_5_a(int size, t_stack *stack);

/*✅-----------------------------sort_utils.c-------------------------------*/

int			get_smallest(int size, int *chunk);
int			get_largest(int size, int *chunk);
int			get_position(int size, int num, int *chunk);
void		select_pivot(int size, int *chunk, t_rules *rules);
void		init_value(t_rules *rules);

/*✅------------------------------stack_a.c---------------------------------*/

void		push_a_to_b(int size, t_stack *stack, int *chunk_count_in_b);

/*✅-----------------------------stack_b.c----------------------------------*/

void		push_b_to_a(int size, t_stack *stack, int *chunk_count_in_b);

#endif

/*==========================================================================*/