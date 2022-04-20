#include "../push_swap.h"

void	init_value(t_stack *stack)
{
	stack -> ra = 0;
	stack -> rb = 0;
	stack -> pa = 0;
	stack -> pb = 0;
}
/*----------------------------------------------------------------------------*/
void	select_pivot_a(t_stack *stack)
{
	long	min;
	long	max;

	min = get_smallest_a(stack);
	max = get_largest_a(stack);
	stack -> piv_big = (min + max) / 2;
	stack -> piv_small = (min + stack -> piv_big) / 2;
}

/*----------------------------------------------------------------------------*/
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