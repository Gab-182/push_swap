#include "../push_swap.h"

/*----------------------------------------------------------------------------*/
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
		if (stack -> base_a[stack -> len_a - 1] == max)
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
			swap_a(stack);
		reverse_rotate_a(stack);
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
void	handle_arg_three_a(t_stack *stack)
{
	int	min;
	int	max;

	min = get_smallest_a(stack);
	max = get_largest_a(stack);
	if (stack -> base_a[0] == min)
		arg_three_top_min_a(stack, max);
	else if (stack -> base_a[1] == min)
		arg_three_middle_min_a(stack, max);
	else if (stack -> base_a[2] == min)
		arg_three_bottom_min_a(stack, max);
}

/*----------------------------------------------------------------------------*/
void	handle_arg_two_a(t_stack *stack)
{
		if (stack -> base_a[0] > stack -> base_a[1])
			swap_a(stack);
}

/*----------------------------------------------------------------------------*/
void	handle_arg_two_b(t_stack *stack)
{
	if (stack -> base_b[0] < stack -> base_b[1])
		swap_b(stack);
	push_a(stack);
	push_a(stack);
}

/*----------------------------------------------------------------------------*/
void	handle_under_three(int size, t_stack *stack)
{
	if (size == 3)
		handle_arg_three_a(stack);
	else if (size == 2)
		handle_arg_two_a(stack);
}

/*============================================================*/
int			mid_val_a(t_stack *stack)
{
	int	i;

	i = 0;
	stack -> temp_a = (int *)malloc(sizeof(int) * stack->len_a);
	while (i < stack -> len_a)
	{
		stack -> temp_a[i] = stack -> base_a[i];
		i++;
	}
	return (helping_sort(stack -> temp_a));
}

/*----------------------------------------------------------------------------*/
void	sort_five_a(int size, t_stack *stack)
{
	int	mid;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	mid = mid_val_a(stack);
	while (size--)
	{
		if (stack -> base_a[0] < mid)
		{
			push_b(stack);
			push++;
		}
		else
		{
			rotate_a(stack);
			rotate++;
		}
		if (push == 2)
			break ;
	}
	while (rotate--)
		reverse_rotate_a(stack);
}

/*----------------------------------------------------------------------------*/
void	hanlde_sort_five(int size, t_stack *stack)
{
	sort_five_a(size, stack);
	handle_arg_three_a(stack);
	handle_arg_two_b(stack);
}

/*----------------------------------------------------------------------------*/