#include "../push_swap.h"

/*----------------------------------------------------------------------------*/
/**
 * @brief Get the smallest number in the stack a.
 * 
 * @param stack 
 * @return int 
 */
int	get_smallest_a(t_stack *stack)
{
	int	i;
	int	smallest_num;

	i = 1;
	smallest_num = stack -> base_a[0];
	while (i < stack -> len_a)
	{
		if (smallest_num > stack -> base_a[i])
			smallest_num = stack -> base_a[i];
		i++;
	}
	return (smallest_num);
}

/*----------------------------------------------------------------------------*/
/**
 * @brief Get the position of the smallest number.
 * 
 * @param stack 
 * @param smallest_num 
 * @return int 
 */
int	get_smallest_position(t_stack *stack, int smallest_num)
{
	int	i;

	i = 0;
	while (i < stack -> len_a)
	{
		if (smallest_num == stack -> base_a[i])
			return (i);
		i++;
	}
	return (0);
}

/*----------------------------------------------------------------------------*/
/**
 * @brief Get the largest number in the stack a.
 * 
 * @param stack 
 * @return int 
 */
int	get_largest_a(t_stack *stack)
{
	int	i;
	int max;

	i = 1;
	max = stack -> base_a[0];
	while(i < stack -> len_a)
	{
		if(max < stack -> base_a[i])
			max = stack -> base_a[i];
		i++;
	}
	return (max);
}
/*----------------------------------------------------------------------------*/
/**
 * @brief Get the smallest number in the stack b.
 * 
 * @param stack 
 * @return int 
 */
int	get_smallest_b(t_stack *stack)
{
	int	i;
	int	smallest_num;

	i = 1;
	smallest_num = stack -> base_b[0];
	while (i < stack -> len_b)
	{
		if (smallest_num > stack -> base_b[i])
			smallest_num = stack -> base_b[i];
		i++;
	}
	return (smallest_num);
}

/*----------------------------------------------------------------------------*/
/**
 * @brief Get the largest number in the stack b.
 * 
 * @param stack 
 * @return int 
 */
int	get_largest_b(t_stack *stack)
{
	int	i;
	int max;

	i = 1;
	max = stack -> base_b[0];
	while(i < stack -> len_b)
	{
		if(max < stack -> base_b[i])
			max = stack -> base_b[i];
		i++;
	}
	return (max);
}
/*----------------------------------------------------------------------------*/