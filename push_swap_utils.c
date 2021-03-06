/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:19:22 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/10 00:03:58 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*✅-------------------------------------------------------------------------*/
/**
 * @brief copy the full length of "size" the content from one stack to another 
 * 
 * @param dst 
 * @param src 
 * @param size 
 * @return void* 
 */
void	ft_stack_cpy(int *dst, int *src, int size)
{
	int	i;

	i = 0;
	if (!src)
		return ;
	if (size > 0)
	{
		while (i < size)
		{
			dst[i] = src[i];
			i++;
		}
	}
}

/*✅--------------------------------------------------------------------------*/
/**
 * @brief Adding numbers to the end of the array of integer, the number
 * should be specified in the arguments.
 * 
 * @param stack 
 * @param num 
 */
void	add_last(t_stack *stack, int num)
{
	stack -> len_a = stack -> len_a + 1;
	if (stack -> len_a >= 2)
	{
		stack -> temp_a = ft_calloc(sizeof(int), (stack -> len_a));
		if (!stack -> temp_a)
			free_stack(stack -> temp_a, 'e');
		ft_stack_cpy(stack -> temp_a, stack -> base_a, stack -> len_a - 1);
		stack -> temp_a[stack -> len_a - 1] = num;
		free_stack(stack -> base_a, 'n');
		stack -> base_a = ft_calloc(sizeof(int), (stack -> len_a));
		if (!stack -> base_a)
			free_stack(stack -> base_a, 'e');
		ft_stack_cpy(stack -> base_a, stack -> temp_a, stack -> len_a);
		free_stack(stack -> temp_a, 'n');
	}
	else
	{
		stack -> base_a = ft_calloc(sizeof(int), 1);
		if (!stack -> base_a)
			free_stack(stack -> base_a, 'e');
		stack -> base_a[0] = num;
	}
}

/*✅--------------------------------------------------------------------------*/
/**
 * @brief check if the stack is already sorted.
 * 
 * @param stack 
 * @return int 
 */
int	is_sorted(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < stack->len_a)
	{
		if (!(stack -> base_a[i] < stack -> base_a[j]))
			return (1);
		i++;
		j++;
	}
	return (0);
}

/*============================================================================*/