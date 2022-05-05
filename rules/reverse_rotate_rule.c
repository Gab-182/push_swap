/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_rule.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:56:06 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/05 09:35:11 by gabdoush         ###   ########.fr       */
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
	stack->temp_a = ft_calloc(sizeof(int), stack->len_a);
	if (!stack->temp_a)
		free_stack(stack->temp_a, 'e');
	while (i < stack->len_a)
	{
		stack->temp_a[i] = stack->base_a[j];
		i++;
		j++;
	}
	stack->temp_a[0] = stack->base_a[stack->len_a - 1];
	free_stack(stack->base_a, 'n');
	stack->base_a = ft_calloc(sizeof(int), stack->len_a);
	if (!stack->base_a)
		free_stack(stack->base_a, 'n');
	ft_stack_cpy(stack->base_a, stack->temp_a, stack->len_a);
	free_stack(stack->temp_a, 'n');
}

/*✅--------------------------------------------------------------------------*/

void	reverse_rotate_b(t_stack *stack)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	stack->temp_b = ft_calloc(sizeof(int), stack->len_b);
	if (!stack->temp_b)
		free_stack(stack->temp_b, 'e');
	while (i < stack->len_b)
	{
		stack->temp_b[i] = stack->base_b[j];
		i++;
		j++;
	}
	stack->temp_b[0] = stack->base_b[stack->len_b - 1];
	ft_stack_cpy(stack->base_b, stack->temp_b, stack->len_b);
	free_stack(stack->temp_b, 'n');
}

/*✅--------------------------------------------------------------------------*/
void	reverse_rotate_a_b(t_stack *stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
}

/*============================================================================*/