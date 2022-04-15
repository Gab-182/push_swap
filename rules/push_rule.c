/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:57:54 by gabdoush          #+#    #+#             */
/*   Updated: 2022/04/11 04:31:12 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*✅-----------------------------------------------------------*/
void	push_b(t_stack *stack)
{
	int	i;

	if (stack->base_a && stack->len_a)
	{
		stack->temp_b = (int *)malloc(sizeof(int) * (stack->len_b + 1));
		stack->len_b = stack->len_b + 1;
		i = 0;
		while (i < stack->len_b - 1 && stack->len_b > 1)
		{
			stack->temp_b[i + 1] = stack->base_b[i];
			i++;
		}
		stack->temp_b[0] = stack->base_a[0];
		if (stack->len_b > 0)
			free(stack->base_b);
		stack->base_b = (int *)malloc(sizeof(int) * stack->len_b);
		i = 0;
		while (i < stack->len_b)
		{
			stack->base_b[i] = stack->temp_b[i];
			i++;
		}
		free(stack->temp_b);
		allocate_temp_free_base_a(stack);
	}
	printf("pb\n");
	stack -> rules_number += 1;
}

/*✅-----------------------------------------------------------*/
void	push_a(t_stack *stack)
{
	int	i;

	if (stack->base_b && stack->len_b)
	{
		stack->temp_a = (int *)malloc(sizeof(int) * (stack->len_a + 1));
		stack->len_a = stack->len_a + 1;
		i = 0;
		while (i < stack->len_a - 1 && stack->len_a > 1)
		{
			stack->temp_a[i + 1] = stack->base_a[i];
			i++;
		}
		stack->temp_a[0] = stack->base_b[0];
		if (stack->len_a > 0)
			free(stack->base_a);
		stack->base_a = (int *)malloc(sizeof(int) * stack->len_a);
		i = 0;
		while (i < stack->len_a)
		{
			stack->base_a[i] = stack->temp_a[i];
			i++;
		}
		free(stack->temp_a);
		allocate_temp_free_base_b(stack);
	}
	printf("pa\n");
	stack -> rules_number += 1;
}

/*======================================================================*/