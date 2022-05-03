/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:13:28 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/03 16:14:01 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*----------------------------------------------------------------------------*/
/**
 * @brief Get the smallest number in the chunk.
 * 
 * @param stack 
 * @return int 
 */
int	get_smallest(int size, int *chunk)
{
	int	i;
	int	smallest_num;

	i = 1;
	smallest_num = chunk[0];
	while (i < size)
	{
		if (smallest_num > chunk[i])
			smallest_num = chunk[i];
		i++;
	}
	return (smallest_num);
}

/*----------------------------------------------------------------------------*/
/**
 * @brief Get the largest number in the chunk.
 * 
 * @param stack 
 * @param size
 * @return int 
 */
int	get_largest(int size, int *chunk)
{
	int	i;
	int	max;

	i = 1;
	max = chunk[0];

	while (i < size)
	{
		if (max < chunk[i])
			max = chunk[i];
		i++;
	}
	return (max);
}

/*----------------------------------------------------------------------------*/
/**
 * @brief Get the number position in the chunk.
 * 
 * @param stack 
 * @param num 
 * @return int 
 */
int	get_position(int size, int num, int *chunk)
{
	int	i;

	i = 0;

	while (i <= size)
	{
		if (num == chunk[i])
			return (i);
		i++;
	}
	return (0);
}

/*----------------------------------------------------------------------------*/
/**
 * @brief initilize part of the struct from the header file (ra, rb, pa, pb).
 * 
 * @param rules 
 */
void	init_value(t_rules *rules)
{
	rules -> ra = 0;
	rules -> rb = 0;
	rules -> pa = 0;
	rules -> pb = 0;
}

/*----------------------------------------------------------------------------*/
/**
 * @brief define the big and the small pivot for the stack a.
 * 
 * @param size 
 * @param chunk 
 * @param rules 
 */
void	select_pivot(int size, int *chunk, t_rules *rules)
{
	long	min;
	long	max;

	min = get_smallest(size, chunk);
	max = get_largest(size, chunk);
	rules -> piv_big = (min + max) / 2;
	rules -> piv_small = (min + rules -> piv_big) / 2;
}

/*----------------------------------------------------------------------------*/
