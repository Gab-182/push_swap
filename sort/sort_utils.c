#include "../push_swap.h"

/*----------------------------------------------------------------------------*/
/**
 * @brief Get the smallest number in the chunk.
 * 
 * @param stack 
 * @return int 
 */
int	get_smallest(int size, int *chunk, t_stack *stack)
{
	int	i;
	int	smallest_num;

	i = 1;
	smallest_num = chunk[0];
	if (size == stack -> len_a)
		size = size - 1;
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
 * @return int 
 */
int	get_largest(int size, int *chunk, t_stack *stack)
{
	int	i;
	int max;

	i = 1;
	max = chunk[0];
	if (size == stack -> len_a)
		size = size - 1;
	while(i < size)
	{
		if(max < chunk[i])
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
int	get_position(int size, int num, int *chunk, t_stack *stack)
{
	int	i;

	i = 0;
	if (size == stack -> len_a)
		size = size - 1;
	while (i < size)
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
 * @param stack 
 */
void	init_value(t_stack *stack)
{
	stack -> ra = 0;
	stack -> rb = 0;
	stack -> pa = 0;
	stack -> pb = 0;
}
/*----------------------------------------------------------------------------*/
/**
 * @brief define the big and the small pivot for the stack a.
 * 
 * @param stack 
 */
void	select_pivot(int size, int* chunk, t_stack *stack)
{
	long	min;
	long	max;

	min = get_smallest(size, chunk, stack);
	max = get_largest(size, chunk, stack);
	// for comparing inside stack a.
	stack -> piv_big = (min + max) / 2;
	// for comparing inside stack b.
	stack -> piv_small = (min + stack -> piv_big) / 2;
}

/*----------------------------------------------------------------------------*/
