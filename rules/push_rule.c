/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:57:54 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/05 12:02:03 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*✅-----------------------------------------------------------*/
void	push_b(t_stack *stack)
{
	int	i;

	if (stack -> base_a && stack -> len_a)
	{
		stack -> temp_b = ft_calloc(sizeof(int), (stack->len_b + 1));
		if (!stack -> temp_b)
			free_stack(stack -> temp_b, 'e');
		stack->len_b = stack->len_b + 1;
		i = 0;
		while (i < stack->len_b - 1 && stack->len_b > 1)
		{
			stack->temp_b[i + 1] = stack->base_b[i];
			i++;
		}
		stack->temp_b[0] = stack->base_a[0];
		free_stack(stack->base_b, 'n');
		stack->base_b = ft_calloc(sizeof(int), stack->len_b);
		if (!stack->base_b)
			free_stack(stack -> base_b, 'e');
		ft_stack_cpy(stack -> base_b, stack -> temp_b, stack -> len_b);
		free_stack(stack->temp_b, 'n');
		allocate_temp_free_base_a(stack);
	}
}

/*✅-----------------------------------------------------------*/
void	push_a(t_stack *stack)
{
	int	i;

	if (stack->base_b && stack->len_b)
	{
		stack -> temp_a = ft_calloc(sizeof(int), (stack->len_a + 1));
		if (!stack->temp_a)
			free_stack(stack->temp_a, 'e');
		stack->len_a = stack->len_a + 1;
		i = 0;
		while (i < stack->len_a - 1 && stack->len_a > 1)
		{
			stack->temp_a[i + 1] = stack->base_a[i];
			i++;
		}
		stack -> temp_a[0] = stack -> base_b[0];
		free_stack(stack -> base_a, 'n');
		stack -> base_a = ft_calloc(sizeof(int), stack -> len_a);
		if (!stack -> base_a)
			free_stack(stack->base_a, 'e');
		ft_stack_cpy(stack -> base_a, stack -> temp_a, stack -> len_a);
		free_stack(stack -> temp_a, 'n');
		allocate_temp_free_base_b(stack);
	}
}

/*======================================================================*/