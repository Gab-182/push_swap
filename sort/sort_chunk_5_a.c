/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_5_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:53:28 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/08 11:25:25 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*✅-------------------------------------------------------------------------*/
void	bubble_sort_a(int *chunk)
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
int	get_middle_num_five_a(t_stack *stack)
{
	int	i;

	i = 0;
	stack -> temp_a = ft_calloc(sizeof(int), 5);
	if (!stack -> temp_a)
		free_stack(stack -> temp_a, 'e');
	while (i < 5)
	{
		stack -> temp_a[i] = stack -> base_a[i];
		i++;
	}
	bubble_sort_a(stack -> temp_a);
	stack -> middle_num = stack -> temp_a[2];
	free_stack(stack -> temp_a, 'n');
	return (stack -> middle_num);
}

/*----------------------------------------------------------------------------*/
/**
 * @brief 😒😒😒 Helper function for sort_five_a() {just for Norm 😒😒😒 }
 * 
 * @param size 
 * @param stack 
 * @param middle_num 
 * @return int 
 */
int	helper_sort_five_a(int size, t_stack *stack, int middle_num)
{
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	while (size--)
	{
		if (stack -> base_a[0] < middle_num)
		{
			push_b(stack);
			push++;
		}
		else
		{
			rotate_a(stack);
			write(1, "ra\n", 3);
			rotate++;
		}
		if (push == 2)
			break ;
	}
	return (rotate);
}

/*----------------------------------------------------------------------------*/
void	sort_five_a(int size, t_stack *stack)
{
	int	rotate;
	int	middle_num;

	middle_num = get_middle_num_five_a(stack);
	rotate = helper_sort_five_a(size, stack, middle_num);
	while (rotate--)
	{
		reverse_rotate_a(stack);
		write(1, "rra\n", 4);
	}
}

/*✅--------------------------------------------------------------------------*/
void	sort_chunk_5_a(int size, t_stack *stack)
{
	sort_five_a(size, stack);
	sort_chunk_3_a(3, stack);
	sort_2_b(stack);
}

/*============================================================================*/