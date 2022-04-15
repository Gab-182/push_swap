#include "push_swap.h"

/*----------------------------------------------------------------------------*/
/**
 * @brief Get the smallest number
 * 
 * @param stack 
 * @return int 
 */
int	get_smallest(t_stack *stack)
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