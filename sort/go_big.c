#include "../push_swap.h"

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
void	select_pivot_a(t_stack *stack)
{
	long	min;
	long	max;

	min = get_smallest_a(stack);
	max = get_largest_a(stack);
	// for stack a.
	stack -> piv_big = (min + max) / 2;
	// for stack b.
	stack -> piv_small = (min + stack -> piv_big) / 2;
}

/*----------------------------------------------------------------------------*/
/**
 * @brief define the big and the small pivot for the stack b.
 * 
 * @param stack 
 */
void	select_pivot_b(t_stack *stack)
{
	long	min;
	long	max;

	min = get_smallest_b(stack);
	max = get_largest_b(stack);
	stack -> piv_big = (min + max) / 2;
	stack -> piv_small = (min + stack -> piv_big) / 2;
}

/*----------------------------------------------------------------------------*/
