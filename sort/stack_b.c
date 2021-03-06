/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:15:09 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/10 03:48:51 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*✅-------------------------------------------------------------------------*/
int	small_chunks_b(int size, t_stack *stack)
{
	if (size == 0)
		return (0);
	else if (size == 1)
	{
		push_a(stack);
		return (0);
	}
	else if (size == 2)
	{
		sort_2_b(stack);
		return (0);
	}
	else if (size == 3)
	{
		sort_chunk_3_b(3, stack);
		return (0);
	}
	else if (size == 5)
	{
		sort_chunk_5_b(5, stack);
		return (0);
	}
	else
		return (1);
}

/*✅-------------------------------------------------------------------------*/
void	push_rotate_b(t_stack *stack, t_rules *rules)
{
	if (stack -> base_b[0] <= rules -> piv_small && stack -> len_b > 1)
	{
		rotate_b(stack);
		write(1, "rb\n", 3);
		rules -> rb++;
	}
	else
	{
		push_a(stack);
		rules -> pa++;
		if (stack -> base_a[0] <= rules -> piv_big && stack -> len_a > 1)
		{
			rotate_a(stack);
			write(1, "ra\n", 3);
			rules -> ra++;
		}
	}
}

/*✅-------------------------------------------------------------------------*/
void	back_to_ra(t_stack *stack, t_rules *rules)
{
	int	rrr;
	int	rem;

	rrr = rules -> rb;
	rem = rules -> ra - rrr;
	while (rrr--)
		reverse_rotate_a_b(stack);
	while (rem-- && stack -> len_a > 1)
	{
		reverse_rotate_a(stack);
		write(1, "rra\n", 4);
	}
}

/*✅-------------------------------------------------------------------------*/
void	back_to_rb(t_stack *stack, t_rules *rules)
{
	int	rrr;
	int	rem;

	rrr = rules -> ra;
	rem = rules -> rb - rrr;
	while (rrr--)
		reverse_rotate_a_b(stack);
	while (rem-- && stack -> len_b > 1)
	{
		reverse_rotate_b(stack);
		write(1, "rrb\n", 4);
	}
}

/*✅-------------------------------------------------------------------------*/
void	push_b_to_a(int size, t_stack *stack, int *chunk_count_in_b)
{
	int		temp;
	t_rules	rules;

	(*chunk_count_in_b)++;
	if (!small_chunks_b(size, stack))
		return ;
	init_value(&rules);
	select_pivot(size, stack -> base_b, &rules);
	temp = size;
	while (temp--)
		push_rotate_b(stack, &rules);
	push_a_to_b(rules.pa - rules.ra, stack, chunk_count_in_b);
	if (rules.ra > rules.rb)
		back_to_ra(stack, &rules);
	else
		back_to_rb(stack, &rules);
	push_a_to_b(rules.ra, stack, chunk_count_in_b);
	push_b_to_a(rules.rb, stack, chunk_count_in_b);
}

/*============================================================================*/