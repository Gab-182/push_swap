#include "../push_swap.h"

/*============================================================================*/
void	sort_2_b(t_stack *stack)
{
	if(stack-> base_b[0] < stack-> base_b[1])
	{
		swap_b(stack);
		ft_putstr("sb\n");
	}
	push_a(stack);
	push_a(stack);
	ft_putstr("pa\npa\n");
}

/*----------------------------------------------------------------------------*/
void	arg_three_top_min_b(t_stack *stack, int max)
{
	if (stack -> len_b == 3)
	{
		rotate_b(stack);
		ft_putstr("rb\n");
		if (stack -> base_b[1] == max)
		{
			swap_b(stack);
			ft_putstr("sb\n");
		}
	}
	else
	{
		swap_b(stack);
		ft_putstr("sb\n");
		rotate_b(stack);
		ft_putstr("rb\n");
		swap_b(stack);
		ft_putstr("sb\n");
		reverse_rotate_b(stack);
		ft_putstr("rrb\n");
		if (stack -> base_b[1] == max)
		{
			swap_b(stack);
			ft_putstr("sb\n");
		}
	}
}

/*----------------------------------------------------------------------------*/
void	arg_three_middle_min_b(t_stack *stack, int max)
{
	if (stack -> len_b == 3)
	{
		reverse_rotate_b(stack);
		ft_putstr("rrb\n");
		if (stack -> base_b[1] == max)
		{
			swap_b(stack);
			ft_putstr("sb\n");
		}
	}
	else
	{
		rotate_b(stack);
		ft_putstr("rb\n");
		swap_b(stack);
		ft_putstr("sb\n");
		reverse_rotate_b(stack);
		ft_putstr("rrb\n");
		if (stack -> base_b[1] == max)
		{
			swap_b(stack);
			ft_putstr("sb\n");
		}
	}
}

/*----------------------------------------------------------------------------*/
void	arg_three_bottom_min_b(t_stack *stack, int max)
{
	if (stack -> base_b[1] == max)
	{
		swap_b(stack);
		ft_putstr("sb\n");
	}
}

/*----------------------------------------------------------------------------*/
void	 sort_chunk_3_b(int size, t_stack *stack)
{
	int	min;
	int	max;

	min = get_smallest(size, stack -> base_b);
	max = get_largest(size, stack -> base_b);
	if (stack -> base_b[0] == min)
		arg_three_top_min_b(stack, max);
	else if (stack -> base_b[1] == min)
		arg_three_middle_min_b(stack, max);
	else if (stack -> base_b[2] == min)
		arg_three_bottom_min_b(stack, max);
	push_a(stack);
	push_a(stack);
	push_a(stack);
	ft_putstr("pa\npa\npa\n");
}

/*============================================================================*/