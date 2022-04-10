/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rule.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:55:56 by gabdoush          #+#    #+#             */
/*   Updated: 2022/02/17 19:43:57 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*✅-----------------------------------------------------------*/
void	rotate_a(t_stack *stack)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	stack->temp_a = (int *)malloc(sizeof(int) * stack->len_a);
	while (i < stack->len_a)
	{
		stack->temp_a[j] = stack->base_a[i];
		i++;
		j++;
	}
	stack->temp_a[stack->len_a - 1] = stack->base_a[0];
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
	printf("ra\n");
}

/*✅-----------------------------------------------------------*/
void	rotate_b(t_stack *stack)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	stack->temp_b = (int *)malloc(sizeof(int) * stack->len_b);
	while (i < stack->len_b)
	{
		stack->temp_b[j] = stack->base_b[i];
		i++;
		j++;
	}
	stack->temp_b[stack->len_b - 1] = stack->base_b[0];
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
	printf("rb\n");
}

/*✅-----------------------------------------------------------*/
void	rotate_a_b(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
	printf("rr\n");
}

/*======================================================================*/