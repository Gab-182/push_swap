/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_5_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:13:05 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/08 09:59:35 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*============================================================================*/
void	bubble_sort_5(int *chunk)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5 - i - 1)
		{
			if (chunk[j] > chunk[j + 1])
			{
				temp = chunk[j];
				chunk[j] = chunk[j + 1];
				chunk[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

/*✅--------------------------------------------------------------------------*/
int	get_middle_num_five_b(t_stack *stack)
{
	int	i;

	i = 0;
	stack -> temp_b = ft_calloc(sizeof(int), 5);
	if (!(stack -> temp_b))
		free_stack(stack -> temp_b, 'e');
	while (i < 5)
	{
		stack -> temp_b[i] = stack -> base_b[i];
		i++;
	}
	bubble_sort_5(stack -> temp_b);
	stack -> middle_num = stack -> temp_b[2];
	free_stack(stack -> temp_b, 'n');
	return (stack -> middle_num);
}

/*----------------------------------------------------------------------------*/
void	sort_chunk_5_b(int size, t_stack *stack)
{
	int	push;
	int	rotate;
	int	middle_num;

	middle_num = get_middle_num_five_b(stack);
	push = 0;
	rotate = 0;
	while (size--)
	{
		if (stack -> base_b[0] >= middle_num)
		{
			push_a(stack);
			push++;
		}
		else
		{
			rotate_b(stack);
			write(1, "rb\n", 3);
			rotate++;
		}
		if (push == 3)
			break ;
	}
	while (rotate--)
	{
		reverse_rotate_b(stack);
		write(1, "rrb\n", 4);
	}
	sort_chunk_3_a(3, stack);
	sort_2_b(stack);
}

/*============================================================================*/