/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorting_a_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:09:37 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/05 10:24:31 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*============================================================================*/
void	smallest_num_scond_spot_5(t_stack *stack)
{
	swap_a(stack);
	if (is_sorted(stack) == 1)
	{
		push_b(stack);
		sort_4_a(4, stack);
		push_a(stack);
	}
}

/*----------------------------------------------------------------------------*/
void	smallest_num_third_spot_5(t_stack *stack)
{
	rotate_a(stack);
	swap_a(stack);
	if (is_sorted(stack) == 1)
	{
		push_b(stack);
		sort_4_a(4, stack);
		push_a(stack);
	}
}

/*----------------------------------------------------------------------------*/
void	smallest_num_fourth_spot_5(t_stack *stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_a(stack);
	if (is_sorted(stack) == 1)
	{
		push_b(stack);
		sort_4_a(4, stack);
		push_a(stack);
	}
}

/*----------------------------------------------------------------------------*/
void	smallest_num_fifth_spot_5(t_stack *stack)
{
	reverse_rotate_a(stack);
	if (is_sorted(stack) == 1)
	{
		push_b(stack);
		sort_4_a(4, stack);
		push_a(stack);
	}
}

/*----------------------------------------------------------------------------*/
/**
 * @brief Sorting 5 numbers in stack a according to the smaller number position
 * in the stack a.
 * 
 * @param size 
 * @param chunk 
 * @param stack 
 */
void	sort_5_a(int size, t_stack *stack)
{
	int	smallest_num;

	smallest_num = get_smallest(5, stack -> base_a);
	if (get_position(5, smallest_num, stack -> base_a) == 0)
	{
		push_b(stack);
		sort_4_a(size, stack);
		push_a(stack);
	}
	else if (get_position(5, smallest_num, stack -> base_a) == 1)
		smallest_num_scond_spot_5(stack);
	else if (get_position(5, smallest_num, stack -> base_a) == 2)
		smallest_num_third_spot_5(stack);
	else if (get_position(5, smallest_num, stack -> base_a) == 3)
		smallest_num_fourth_spot_5(stack);
	else if (get_position(5, smallest_num, stack -> base_a) == 4)
		smallest_num_fifth_spot_5(stack);
}
/*============================================================================*/