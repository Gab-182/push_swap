/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rule_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:56:19 by gabdoush          #+#    #+#             */
/*   Updated: 2022/02/17 19:44:36 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*✅-----------------------------------------------------------*/
void	allocate_temp_free_base_a(t_stack *stack)
{
	int	i;

	stack->temp_a = (int *)malloc(sizeof(int) * (stack->len_a - 1));
	stack->len_a = stack->len_a - 1;
	i = 0;
	while (i < stack->len_a)
	{
		stack->temp_a[i] = stack->base_a[i + 1];
		i++;
	}
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
}

/*✅-----------------------------------------------------------*/
void	allocate_temp_free_base_b(t_stack *stack)
{
	int	i;

	stack->temp_b = (int *)malloc(sizeof(int) * (stack->len_b - 1));
	stack->len_b = stack->len_b - 1;
	i = 0;
	while (i < stack->len_b)
	{
		stack->temp_b[i] = stack->base_b[i + 1];
		i++;
	}
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
}

/*======================================================================*/