/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_3_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:11:53 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/03 21:11:21 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	arg_three_top_min_a(t_stack *stack, int max)
{
	if (stack -> len_a == 3)
	{
		if (stack -> base_a[1] == max)
		{
			reverse_rotate_a(stack);
			printf("rra\n");
			swap_a(stack);
			printf("sa\n");
		}
	}
	else
	{
		if (stack -> base_a[1] == max)
		{
			rotate_a(stack);
			printf("ra\n");
			swap_a(stack);
			printf("sa\n");
			reverse_rotate_a(stack);
			printf("rra\n");
		}
	}
}

/*----------------------------------------------------------------------------*/
void	arg_three_middle_min_a(t_stack *stack, int max)
{
	if (stack -> len_a == 3)
	{
		if (stack -> base_a[2] == max)
		{
			swap_a(stack);
			printf("sa\n");
		}
		else
		{
			rotate_a(stack);
			printf("ra\n");
		}
	}
	else
	{
		swap_a(stack);
		printf("sa\n");
		if (stack -> base_a[1] == max)
		{
			rotate_a(stack);
			printf("ra\n");
			swap_a(stack);
			printf("sa\n");
			reverse_rotate_a(stack);
			printf("rra\n");
		}
	}
}

/*----------------------------------------------------------------------------*/
void	arg_three_bottom_min_a(t_stack *stack, int max)
{
	if (stack -> len_a == 3)
	{
		if (stack -> base_a[0] == max)
		{
			swap_a(stack);
			printf("sa\n");
		}
		reverse_rotate_a(stack);
		printf("rra\n");
	}
	else
	{
		if (stack -> base_a[0] == max)
		{
			swap_a(stack);
			printf("sa\n");
		}

		rotate_a(stack);
		printf("ra\n");
		swap_a(stack);
		printf("sa\n");
		reverse_rotate_a(stack);
		printf("rra\n");
		swap_a(stack);
		printf("sa\n");
	}
}

/*----------------------------------------------------------------------------*/
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