/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:14:07 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/10 03:48:51 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*✅-------------------------------------------------------------------------*/
int	small_chunks_a(int size, t_stack *stack)
{
	if (size == 1 || size == 0)
		return (0);
	else if (size == 2)
	{
		sort_2_a(stack);
		return (0);
	}
	else if (size == 3)
	{
		sort_chunk_3_a(3, stack);
		return (0);
	}
	else if (size == 5)
	{
		sort_chunk_5_a(5, stack);
		return (0);
	}
	else
		return (1);
}

/*✅--------------------------------------------------------------------------*/
/**
 * @brief if the first numbers in the stack _a bigger than the (big pivot) 
 * push it to the stack_b, else rotate the stack_a.
 * 
 * @param stack 
 */
void	compare_to_pivot(t_stack *stack, t_rules *rules)
{
	if (stack -> base_a[0] > rules-> piv_big)
	{
		rotate_a(stack);
		write(1, "ra\n", 3);
		rules -> ra++;
	}
	else
	{
		push_b(stack);
		rules -> pb++;
		if (stack -> base_b[0] > rules -> piv_small)
		{
			rotate_b(stack);
			write(1, "rb\n", 3);
			rules -> rb++;
		}
	}
}

/*✅-------------------------------------------------------------------------*/
void	compare_to_rb(t_stack *stack, int *chunk_count_in_b, t_rules *rules)
{
	int	rb;
	int	rem;

	rb = rules -> rb;
	rem = rules -> ra - rb;
	if ((*chunk_count_in_b) > 0)
	{
		while (rb--)
			reverse_rotate_a_b(stack);
		while (rem--)
		{
			reverse_rotate_a(stack);
			write(1, "rra\n", 4);
		}
	}
	else
	{
		while (rb--)
		{
			reverse_rotate_b(stack);
			write(1, "rrb\n", 4);
		}
	}
}

/*✅-------------------------------------------------------------------------*/
void	compare_to_ra(t_stack *stack, int *chunk_count_in_b, t_rules *rules)
{
	int	rrr;
	int	rem;

	rrr = rules -> ra;
	rem = rules -> rb - rrr;
	if ((*chunk_count_in_b) > 0)
	{
		while (rrr--)
			reverse_rotate_a_b(stack);
		while (rem--)
		{
			reverse_rotate_b(stack);
			write(1, "rrb\n", 4);
		}
	}
	else
	{
		rrr = rules -> rb;
		while (rrr--)
		{
			reverse_rotate_b(stack);
			write(1, "rrb\n", 4);
		}
	}
}

/*✅--------------------------------------------------------------------------*/
void	push_a_to_b(int size, t_stack *stack, int *chunk_count_in_b)
{
	int		temp;
	t_rules	rules;

	if (!small_chunks_a(size, stack))
		return ;
	init_value(&rules);
	select_pivot(size, stack -> base_a, &rules);
	temp = size;
	while (temp--)
		compare_to_pivot(stack, &rules);
	if (rules.ra > rules.rb)
		compare_to_rb(stack, chunk_count_in_b, &rules);
	else
		compare_to_ra(stack, chunk_count_in_b, &rules);
	push_a_to_b(rules.ra, stack, chunk_count_in_b);
	push_b_to_a(rules.rb, stack, chunk_count_in_b);
	push_b_to_a(rules.pb - rules.rb, stack, chunk_count_in_b);
}

/*============================================================================*/