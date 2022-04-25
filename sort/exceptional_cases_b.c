#include "../push_swap.h"

/*----------------------------------------------------------------------------*/
void	arg_three_top_min_b(t_stack *stack, int max)
{
	if (stack -> len_b == 3)
	{
		rotate_b(stack);
		if (stack ->base_b[1] == max)
			swap_b(stack);
	}
	else
	{
		swap_b(stack);
		rotate_b(stack);
		swap_b(stack);
		reverse_rotate_b(stack);
		if (stack ->base_b[1] == max)
			swap_b(stack);
	}
}

/*----------------------------------------------------------------------------*/
void	arg_three_middle_min_b(t_stack *stack, int max)
{
	if (stack -> len_b == 3)
	{
		reverse_rotate_b(stack);
		if (stack ->base_b[1] == max)
			swap_b(stack);
	}
	else
	{
		rotate_b(stack);
		swap_b(stack);
		reverse_rotate_b(stack);
		if (stack ->base_b[1] == max)
			swap_b(stack);
	}
}

/*----------------------------------------------------------------------------*/
void	arg_three_bottom_min_b(t_stack *stack, int max)
{
	if (stack ->base_b[1] == max)
		swap_b(stack);
}

/*----------------------------------------------------------------------------*/
void	handle_arg_three_b(t_stack *stack)
{
	int	min;
	int	max;

	min = get_smallest_b(stack);
	max = get_largest_b(stack);
	if (stack ->base_b[0] == min)
		arg_three_top_min_b(stack, max);
	else if (stack ->base_b[1] == min)
		arg_three_middle_min_b(stack, max);
	else if (stack ->base_b[2] == min)
		arg_three_bottom_min_b(stack, max);
	push_a(stack);
	push_a(stack);
	push_a(stack);
}

/*----------------------------------------------------------------------------*/
void	handle_under_three_b(int size, t_stack *stack)
{
	if (size == 3)
		handle_arg_three_b(stack);
	else if (size == 2)
		handle_arg_two_b(stack);
	else if (size == 1)
		push_a(stack);
}

/*----------------------------------------------------------------------------*/
int helping_sort(int *temp_stack)
{
	int	i;
	int	j;
	int	tmp;

	i = 5;
	while (--i > 0)
	{
		j = -1;
		while (++j < i)
		{
			if (temp_stack[j] > temp_stack[j + 1])
			{
				tmp = temp_stack[j + 1];
				temp_stack[j + 1] = temp_stack[j];
				temp_stack[j] = tmp;
			}
		}
	}
	return (temp_stack[2]);
}
/*============================================================*/
int			mid_val_b(t_stack *stack)
{
	int	i;

	i = 0;
	stack -> temp_b = (int *)malloc(sizeof(int) * stack->len_b);
	while (i < stack -> len_b)
	{
		stack -> temp_b[i] = stack -> base_b[i];
		i++;
	}
	return (helping_sort(stack -> temp_b));
}
/*----------------------------------------------------------------------------*/
void	sort_five_b(int size, t_stack *stack)
{
	int	mid;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	mid = mid_val_b(stack);
	while (size--)
	{
		if (stack -> base_b[0] >= mid)
		{
			push_a(stack);
			push++;
		}
		else
		{
			rotate_b(stack);
			rotate++;
		}
		if (push == 3)
			break ;
	}
	while (rotate--)
		reverse_rotate_b(stack);
}

/*----------------------------------------------------------------------------*/
void	hanlde_sort_five_b(int size, t_stack *stack)
{
	sort_five_b(size, stack);
	handle_arg_three_a(stack);
	handle_arg_two_b(stack);
}

/*----------------------------------------------------------------------------*/  