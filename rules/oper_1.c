/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:12:34 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/07 19:52:04 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stack *stack)
{
	int *temp;

	temp = malloc((2 + 1) * sizeof(int *));
	temp[0] = stack->base_a[0];
	temp[1] = stack->base_a[1];
	stack->base_a[1] = temp[0];
	stack->base_a[0] = temp[1];
	free(temp);
}

/*----------------------------------------------------------------------------*/
void	swap_b(t_stack *stack)
{
	int		*temp;

	temp = malloc((2 + 1) * sizeof(int *));
	temp[0] = stack->base_b[0];
	temp[1] = stack->base_b[1];
	stack->base_b[1] = temp[0];
	stack->base_b[0] = temp[1];
	free(temp);
}

/*----------------------------------------------------------------------------*/
int	*push(int *stack, int element, int *old_stack, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	stack = ft_calloc(sizeof(int), (size + 1));
	stack[0] = element;
	while (j < size)
	{
		stack[j] = old_stack[i];
		i++;
		j++;
	}
	return (stack);
}

/*----------------------------------------------------------------------------*/
void	push_b(t_stack *stack)
{
	int	*temp;

	if (!stack->base_b)
	{
		stack->base_b = malloc(sizeof(int) * (1));
		stack->base_b[0] = stack->base_a[0];
		stack->len_a -= 1;
		stack->len_b += 1;
		stack->base_a = new_stack(stack->base_a, stack->len_a);
	}
	else
	{
		stack->len_b += 1;
		stack->len_a -= 1;
		temp = stack->base_b;
		stack->base_b = push(stack->base_b, stack->base_a[0],
				stack->base_b, stack->len_b);
		free(temp);
		stack->base_a = new_stack(stack->base_a, stack->len_a);
	}
}

/*----------------------------------------------------------------------------*/
void	push_a(t_stack *stack)
{
	int	*temp;

	stack->len_b -= 1;
	stack->len_a += 1;
	temp = stack->base_a;
	stack->base_a = push(stack->base_a, stack->base_b[0],
			stack->base_a, stack->len_a);
	free(temp);
	stack->base_b = new_stack(stack->base_b, stack->len_b);
}

/*----------------------------------------------------------------------------*/
int	*new_stack(int *stack, int size)
{
	int	*temp;
	int	i;
	int	j;

	temp = stack;
	i = 0;
	j = 1;
	stack = ft_calloc(sizeof(int), size + 1);
	while (i < size)
	{
		stack[i] = temp[j];
		i++;
		j++;
	}
	stack[size] = 0;
	free(temp);
	temp = NULL;
	return (stack);
}

/*----------------------------------------------------------------------------*/