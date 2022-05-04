/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rule_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:56:19 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/04 14:19:45 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*✅-----------------------------------------------------------*/
void	allocate_temp_free_base_a(t_stack *stack)
{
	int	i;

	stack -> temp_a = malloc(sizeof(int) * (stack -> len_a - 1));
	if (!stack -> temp_a)
		free_stack(stack -> temp_a, 'e');
	stack->len_a = stack->len_a - 1;
	i = 0;
	while (i < stack->len_a)
	{
		stack->temp_a[i] = stack->base_a[i + 1];
		i++;
	}
	free_stack(stack->base_a, 'n');
	stack->base_a = malloc(sizeof(int) * stack->len_a);
	if (!stack -> base_a)
		free_stack(stack -> base_a, 'e');
	ft_stack_cpy(stack -> base_a, stack -> temp_a, stack -> len_a);
	free_stack(stack -> temp_a, 'n');
}

/*✅-----------------------------------------------------------*/
void	allocate_temp_free_base_b(t_stack *stack)
{
	int	i;

	stack->temp_b = malloc(sizeof(int) * (stack->len_b - 1));
	if (!stack -> temp_b)
		free_stack(stack -> temp_b, 'e');
	stack->len_b = stack->len_b - 1;
	i = 0;
	while (i < stack->len_b)
	{
		stack->temp_b[i] = stack->base_b[i + 1];
		i++;
	}
	free_stack(stack -> base_b, 'n');
	stack -> base_b = malloc(sizeof(int) * stack -> len_b);
	if (!stack -> base_b)
		free_stack(stack -> base_b, 'e');
	ft_stack_cpy(stack -> base_b, stack -> temp_b, stack -> len_b);
	free_stack(stack -> temp_b, 'n');
}

/*======================================================================*/