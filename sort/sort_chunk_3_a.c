#include "../push_swap.h"


void	arg_three_top_min_a(t_stack *stack, int max)
{
	if (stack -> len_a == 3)
	{
		if (stack -> base_a[1] == max)
		{
			reverse_rotate_a(stack);
			swap_a(stack);
		}
	}
	else
	{
		if (stack -> base_a[1] == max)
		{
			rotate_a(stack);
			swap_a(stack);
			reverse_rotate_a(stack);
		}
	}
}

/*----------------------------------------------------------------------------*/
void	arg_three_middle_min_a(t_stack *stack, int max)
{
	if (stack -> len_a == 3)
	{
		if (stack -> base_a[2] == max)
			swap_a(stack);
		else
			rotate_a(stack);
	}
	else
	{
		swap_a(stack);
		if (stack -> base_a[1] == max)
		{
			rotate_a(stack);
			swap_a(stack);
			reverse_rotate_a(stack);
		}
	}
}

/*----------------------------------------------------------------------------*/
void	arg_three_bottom_min_a(t_stack *stack, int max)
{
	if (stack -> len_a == 3)
	{
		if (stack -> base_a[0] == max)
		{
			swap_a(stack);
			ft_putstr("sa\n");
		}
		reverse_rotate_a(stack);
		ft_putstr("rra\n");
	}
	else
	{
		if (stack -> base_a[0] == max)
			swap_a(stack);

		rotate_a(stack);
		swap_a(stack);
		reverse_rotate_a(stack);
		swap_a(stack);
	}
}

/*----------------------------------------------------------------------------*/
void	sort_chunk_3_a(int size, t_stack *stack)
{
	int	min;
	int	max;

	min = get_smallest(size, stack -> base_a);
	max = get_largest(size, stack -> base_a);
	if (stack -> base_a[0] == min)
		arg_three_top_min_a(stack, max);
	else if (stack -> base_a[1] == min)
		arg_three_middle_min_a(stack, max);
	else if (stack -> base_a[2] == min)
		arg_three_bottom_min_a(stack, max);
}

/*============================================================================*/