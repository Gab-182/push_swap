/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorting_a_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:11:23 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/08 09:56:11 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*============================================================================*/
void	smallest_num_first_spot_4(t_stack *stack)
{
	push_b(stack);
	sort_chunk_3_a(3, stack);
	push_a(stack);
}

/*----------------------------------------------------------------------------*/
void	smallest_num_scond_spot_4(t_stack *stack)
{
	swap_a(stack);
	if (is_sorted(stack) == 1)
	{
		push_b(stack);
		sort_chunk_3_a(3, stack);
		push_a(stack);
	}
}

/*----------------------------------------------------------------------------*/
void	smallest_num_third_spot_4(t_stack *stack)
{
	rotate_a(stack);
	write(1, "ra\n", 3);
	swap_a(stack);
	if (is_sorted(stack) == 1)
	{
		push_b(stack);
		sort_chunk_3_a(3, stack);
		push_a(stack);
	}
}

/*----------------------------------------------------------------------------*/
void	smallest_num_forth_spot_4(t_stack *stack)
{
	reverse_rotate_a(stack);
	write(1, "rra\n", 4);
	if (is_sorted(stack))
	{
		push_b(stack);
		sort_chunk_3_a(3, stack);
		push_a(stack);
	}
}

/*----------------------------------------------------------------------------*/
/**
 * @brief Sorting 4 numbers in stack a according to the smaller number position
 * in the stack a.
 * 
 * @param size 
 * @param chunk 
 * @param stack 
 */
void	sort_4_a(int size, t_stack *stack)
{
	int	smallest_num;

	smallest_num = get_smallest(4, stack -> base_a);
	if (get_position(size, smallest_num, stack -> base_a) == 0)
		smallest_num_first_spot_4(stack);
	else if (get_position(4, smallest_num, stack -> base_a) == 1)
		smallest_num_scond_spot_4(stack);
	else if (get_position(4, smallest_num, stack -> base_a) == 2)
		smallest_num_third_spot_4(stack);
	else if (get_position(4, smallest_num, stack -> base_a) == 3)
		smallest_num_forth_spot_4(stack);
}

/*============================================================================*/