/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorting_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:11:23 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/04 04:18:51 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*----------------------------------------------------------------------------*/
/**
 * @brief Sorting two numbers in stack a.
 * @param stack 
 */
void	sort_2_a(t_stack *stack)
{
	if (stack -> base_a[1] < stack -> base_a[0])
	{
		swap_a(stack);
		printf("sa\n");
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
	{
		push_b(stack);
		printf("pb\n");
		sort_chunk_3_a(3, stack);
		push_a(stack);
		printf("pa\n");
	}
	else if (get_position(4, smallest_num, stack -> base_a) == 1)
	{
		swap_a(stack);
		printf("sa\n");
		if (is_sorted(stack) == 1)
		{
			push_b(stack);
			printf("pb\n");
			sort_chunk_3_a(3, stack);
			push_a(stack);
			printf("pa\n");
		}
	}
	else if (get_position(4, smallest_num, stack -> base_a) == 2)
	{
		rotate_a(stack);
		printf("ra\n");
		swap_a(stack);
		printf("sa\n");
		if (is_sorted(stack) == 1)
		{
			push_b(stack);
			printf("pb\n");
			sort_chunk_3_a(3, stack);
			push_a(stack);
			printf("pa\n");
		}
	}
	else if (get_position(4, smallest_num, stack -> base_a) == 3)
	{
		reverse_rotate_a(stack);
		printf("rra\n");
		if (is_sorted(stack))
		{
			push_b(stack);
			printf("pb\n");
			sort_chunk_3_a(3, stack);
			push_a(stack);
			printf("pa\n");
		}
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
		printf("pb\n");
		sort_4_a(size, stack);
		push_a(stack);
		printf("pa\n");
	}
	else if (get_position(5, smallest_num, stack -> base_a) == 1)
	{
		swap_a(stack);
		printf("sa\n");
		if (is_sorted(stack) == 1)
		{
			push_b(stack);
			printf("pb\n");
			sort_4_a(size, stack);
			push_a(stack);
			printf("pa\n");
		}
	}
	else if (get_position(5, smallest_num, stack -> base_a) == 2)
	{
		rotate_a(stack);
		printf("ra\n");
		swap_a(stack);
		printf("sa\n");
		if (is_sorted(stack) == 1)
		{
			push_b(stack);
			printf("pb\n");
			sort_4_a(size, stack);
			push_a(stack);
			printf("pa\n");
		}
	}
	else if (get_position(5, smallest_num, stack -> base_a) == 3)
	{
		reverse_rotate_a(stack);
		printf("rra\n");
		reverse_rotate_a(stack);
		printf("rra\n");
		if (is_sorted(stack) == 1)
		{
			push_b(stack);
			printf("pb\n");
			sort_4_a(size, stack);
			push_a(stack);
			printf("pa\n");
		}
	}
	else if (get_position(5, smallest_num, stack -> base_a) == 4)
	{
		reverse_rotate_a(stack);
		printf("rra\n");
		if (is_sorted(stack) == 1)
		{
			push_b(stack);
			printf("pb\n");
			sort_4_a(size, stack);
			push_a(stack);
			printf("pa\n");
		}
	}
}
/*----------------------------------------------------------------------------*/