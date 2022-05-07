/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:15:09 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/07 21:01:49 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*============================================================================*/
int	small_chunks_b(int size, t_stack *stack)
{
	if (size == 0)
		return (0);
	else if (size == 1)
	{
		push_a(stack);
		printf("pa\n");
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

/*----------------------------------------------------------------------------*/
void	push_rotate_b(t_stack *stack, t_rules *rules)
{
	if (stack -> base_b[0] <= rules -> piv_small && stack -> len_b > 1)
	{
		rotate_b(stack);
		printf("rb\n");
		rules -> rb++;
	}
	else
	{
		push_a(stack);
		printf("pa\n");
		rules -> pa++;
		if (stack -> base_a[0] <= rules -> piv_big && stack -> len_a > 1)
		{
			rotate_a(stack);
			printf("ra\n");
			rules -> ra++;
		}
	}
}

/*----------------------------------------------------------------------------*/
void	back_to_ra(t_stack *stack, t_rules *rules)
{
	int	rrr;
	int	rem;

	rrr = rules -> rb;
	rem = rules -> ra - rrr;
	while (rrr--)
	{
		reverse_rotate_a_b(stack);
		printf("rrr\n");
	}
	while (rem-- && stack -> len_a > 1)
	{
		reverse_rotate_a(stack);
		printf("rra\n");
	}
}

/*----------------------------------------------------------------------------*/
void	back_to_rb(t_stack *stack, t_rules *rules)
{
	int	rrr;
	int	rem;

	rrr = rules -> ra;
	rem = rules -> rb - rrr;
	while (rrr--)
	{
		reverse_rotate_a_b(stack);
		printf("rrr\n");
	}
	while (rem-- && stack -> len_b > 1)
	{
		reverse_rotate_b(stack);
		printf("rrb\n");
	}
}

/*----------------------------------------------------------------------------*/
void	b_to_a(int size, t_stack *stack, int *cnt)
{
	int		temp;
	t_rules	rules;

	(*cnt)++;
	if (!small_chunks_b(size, stack))
		return ;
	init_value(&rules);
	select_pivot(size, stack -> base_b, &rules);
	temp = size;
	while (temp--)
		push_rotate_b(stack, &rules);
	a_to_b(rules.pa - rules.ra, stack, cnt);
	if (rules.ra > rules.rb)
		back_to_ra(stack, &rules);
	else
		back_to_rb(stack, &rules);
	a_to_b(rules.ra, stack, cnt);
	b_to_a(rules.rb, stack, cnt);
}

/*============================================================================*/