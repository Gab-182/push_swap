/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:14:07 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/08 10:00:14 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*============================================================================*/
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

/*----------------------------------------------------------------------------*/
void	back_to_orig_ra(t_stack *stack, int *cnt, t_rules *rules)
{
	int	rb;
	int	rem;

	rb = rules -> rb;
	rem = rules -> ra - rb;
	if ((*cnt) > 0)
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

/*----------------------------------------------------------------------------*/
void	back_to_orig_rb(t_stack *stack, int *cnt, t_rules *rules)
{
	int	rrr;
	int	rem;

	rrr = rules -> ra;
	rem = rules -> rb - rrr;
	if ((*cnt) > 0)
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
void	a_to_b(int size, t_stack *stack, int *cnt)
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
		back_to_orig_ra(stack, cnt, &rules);
	else
		back_to_orig_rb(stack, cnt, &rules);
	a_to_b(rules.ra, stack, cnt);
	b_to_a(rules.rb, stack, cnt);
	b_to_a(rules.pb - rules.rb, stack, cnt);
}

/*============================================================================*/