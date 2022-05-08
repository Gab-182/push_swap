/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_3_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:11:53 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/08 09:57:45 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*============================================================================*/
/**
 * @brief Sorting two numbers in stack a.
 * @param stack 
 */
void	sort_2_a(t_stack *stack)
{
	if (stack -> base_a[1] < stack -> base_a[0])
		swap_a(stack);
}

/*✅--------------------------------------------------------------------------*/
void	arg_three_top_min_a(t_stack *stack, int max)
{
	if (stack -> len_a == 3)
	{
		if (stack -> base_a[1] == max)
		{
			reverse_rotate_a(stack);
			write(1, "rra\n", 4);
			swap_a(stack);
		}
	}
	else
	{
		if (stack -> base_a[1] == max)
		{
			rotate_a(stack);
			write(1, "ra\n", 3);
			swap_a(stack);
			reverse_rotate_a(stack);
			write(1, "rra\n", 4);
		}
	}
}

/*----------------------------------------------------------------------------*/
void	arg_three_middle_min_a(t_stack *stack, int max)
{
	if (stack -> len_a == 3)
	{
		if (stack -> base_a[2] == max)
			swap_a(stack);
		else
		{
			rotate_a(stack);
			write(1, "ra\n", 3);
		}
	}
	else
	{
		swap_a(stack);
		if (stack -> base_a[1] == max)
		{
			rotate_a(stack);
			write(1, "ra\n", 3);
			swap_a(stack);
			reverse_rotate_a(stack);
			write(1, "rra\n", 4);
		}
	}
}

/*----------------------------------------------------------------------------*/
void	arg_three_bottom_min_a(t_stack *stack, int max)
{
	if (stack -> len_a == 3)
	{
		if (stack -> base_a[0] == max)
			swap_a(stack);
		reverse_rotate_a(stack);
		write(1, "rra\n", 4);
	}
	else
	{
		if (stack -> base_a[0] == max)
			swap_a(stack);
		rotate_a(stack);
		write(1, "ra\n", 3);
		swap_a(stack);
		reverse_rotate_a(stack);
		write(1, "rra\n", 4);
		swap_a(stack);
	}
}

/*✅--------------------------------------------------------------------------*/
void	sort_chunk_3_a(int size, t_stack *stack)
{
	int	min;
	int	max;

	min = get_smallest(size, stack -> base_a);
	max = get_largest(size, stack -> base_a);
	if (stack -> base_a[0] == min)
		arg_three_top_min_a(stack, max);
	else if (stack -> base_a[1] == min)
		arg_three_middle_min_a(stack, max);
	else if (stack -> base_a[2] == min)
		arg_three_bottom_min_a(stack, max);
}

/*============================================================================*/