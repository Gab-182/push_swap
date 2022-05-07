/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_3_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:12:02 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/07 00:25:55 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*============================================================================*/
void	sort_2_b(t_stack *stack)
{
	if (stack -> base_b[0] < stack -> base_b[1])
	{
		swap_b(stack);
		printf("sb\n");
	}
	push_a(stack);
	printf("pa\n");
	push_a(stack);
	printf("pa\n");
}

/*----------------------------------------------------------------------------*/
void	arg_three_top_min_b(t_stack *stack, int max)
{
	if (stack -> len_b == 3)
	{
		rotate_b(stack);
		printf("rb\n");
		if (stack -> base_b[1] == max)
		{
			swap_b(stack);
			printf("sb\n");
		}
	}
	else
	{
		swap_b(stack);
		printf("sb\n");
		rotate_b(stack);
		printf("rb\n");
		swap_b(stack);
		printf("sb\n");
		reverse_rotate_b(stack);
		printf("rrb\n");
		if (stack -> base_b[1] == max)
		{
			swap_b(stack);
			printf("sb\n");
		}
	}
}

/*----------------------------------------------------------------------------*/
void	arg_three_middle_min_b(t_stack *stack, int max)
{
	if (stack -> len_b == 3)
	{
		reverse_rotate_b(stack);
		printf("rrb\n");
		if (stack -> base_b[1] == max)
		{
			swap_b(stack);
			printf("sb\n");
		}
	}
	else
	{
		rotate_b(stack);
		printf("rb\n");
		swap_b(stack);
		printf("sb\n");
		reverse_rotate_b(stack);
		printf("rrb\n");
		if (stack -> base_b[1] == max)
		{
			swap_b(stack);
			printf("sb\n");
		}
	}
}

/*----------------------------------------------------------------------------*/
void	arg_three_bottom_min_b(t_stack *stack, int max)
{
	if (stack -> base_b[1] == max)
	{
		swap_b(stack);
		printf("sb\n");
	}
}

/*----------------------------------------------------------------------------*/
void	sort_chunk_3_b(int size, t_stack *stack)
{
	int	min;
	int	max;

	min = get_smallest(size, stack -> base_b);
	max = get_largest(size, stack -> base_b);
	if (stack -> base_b[0] == min)
		arg_three_top_min_b(stack, max);
	else if (stack -> base_b[1] == min)
		arg_three_middle_min_b(stack, max);
	else if (stack -> base_b[2] == min)
		arg_three_bottom_min_b(stack, max);
	push_a(stack);
	push_a(stack);
	push_a(stack);
	printf("pa\npa\npa\n");
}

/*============================================================================*/