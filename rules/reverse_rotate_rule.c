/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_rule.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:56:06 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/04 13:54:25 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*✅--------------------------------------------------------------------------*/
void	reverse_rotate_a(t_stack *stack)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	stack->temp_a = malloc(sizeof(int) * stack->len_a);
	while (i < stack->len_a)
	{
		stack->temp_a[i] = stack->base_a[j];
		i++;
		j++;
	}
	stack->temp_a[0] = stack->base_a[stack->len_a - 1];
	if (stack->len_a > 0)
		free(stack->base_a);
	stack->base_a = malloc(sizeof(int) * stack->len_a);
	i = 0;
	while (i < stack->len_a)
	{
		stack->base_a[i] = stack->temp_a[i];
		i++;
	}
	free(stack->temp_a);
}

/*✅--------------------------------------------------------------------------*/

void	reverse_rotate_b(t_stack *stack)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	stack->temp_b = malloc(sizeof(int) * stack->len_b);
	while (i < stack->len_b)
	{
		stack->temp_b[i] = stack->base_b[j];
		i++;
		j++;
	}
	stack->temp_b[0] = stack->base_b[stack->len_b - 1];
	i = 0;
	while (i < stack->len_b)
	{
		stack->base_b[i] = stack->temp_b[i];
		i++;
	}
	free(stack->temp_b);
}

/*✅--------------------------------------------------------------------------*/
void	reverse_rotate_a_b(t_stack *stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
}

/*============================================================================*/