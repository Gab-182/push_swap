#include "../push_swap.h"

/*----------------------------------------------------------------------------*/
/**
 * @brief Sorting two numbers in stack a.
 * @param stack 
 */
void	sort_2_a(t_stack *stack)
{
	if (stack -> base_a[1] < stack -> base_a[0])
		swap_a(stack);
}

/*----------------------------------------------------------------------------*/
/**
 * @brief Sorting 3 numbers in stack a.
 * @param stack 
 */
void	sort_3_a(t_stack  *stack)
{
	// 2, 1, 3
	if (stack -> base_a[0] > stack -> base_a[1] \
		&& stack -> base_a[1] < stack -> base_a[2]\
		&& stack -> base_a[0] < stack -> base_a[2])
		swap_a(stack);
	// 2, 3, 1
	else if (stack -> base_a[0] < stack -> base_a[1] \
			&& stack -> base_a[1] > stack -> base_a[2] \
			&& stack -> base_a[0] > stack -> base_a[2])
		reverse_rotate_a(stack);
	// 3, 2, 1
	else if (stack -> base_a[0] > stack -> base_a[1] \
			&& stack -> base_a[1] > stack -> base_a[2] \
			&& stack -> base_a[0] > stack -> base_a[2])
	{
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	// 1, 3, 2
	else if (stack -> base_a[0] < stack -> base_a[1] \
			&& stack -> base_a[1] > stack -> base_a[2] \
			&& stack -> base_a[0] < stack -> base_a[2])
	{
		swap_a(stack);
		rotate_a(stack);
	}
	// 3, 1, 2
	else if (stack -> base_a[0] > stack -> base_a[1] \
			&& stack -> base_a[1] < stack -> base_a[2] \
			&& stack -> base_a[0] > stack -> base_a[2])
		rotate_a(stack);
}

/*----------------------------------------------------------------------------*/
/**
 * @brief Sorting 4 numbers in stack a according to the smaller number position
 * in the stack a.
 * @param stack 
 */
void	sort_4_a(t_stack *stack)
{
	int	smallest_num;

	smallest_num = get_smallest_a(stack);
	if (get_position_a(stack, smallest_num) == 0)
	{
		push_b(stack);
		sort_3_a(stack);
		push_a(stack);
	}
	else if (get_position_a(stack, smallest_num) == 1)
	{
		swap_a(stack);
		push_b(stack);
		sort_3_a(stack);
		push_a(stack);
	}
	else if (get_position_a(stack, smallest_num) == 2)
	{
		rotate_a(stack);
		swap_a(stack);
		push_b(stack);
		sort_3_a(stack);
		push_a(stack);
	}
	else if (get_position_a(stack, smallest_num) == 3)
	{
		reverse_rotate_a(stack);
		push_b(stack);
		sort_3_a(stack);
		push_a(stack);
	}
}

/*----------------------------------------------------------------------------*/
/**
 * @brief Sorting 5 numbers in stack a according to the smaller number position
 * in the stack a.
 * @param stack 
 */
void	sort_5_a(t_stack *stack)
{
	int	smallest_num;

	smallest_num = get_smallest_a(stack);
	if (get_position_a(stack, smallest_num) == 0)
	{
		push_b(stack);
		sort_4_a(stack);
		push_a(stack);
	}
	else if (get_position_a(stack, smallest_num) == 1)
	{
		swap_a(stack);
		push_b(stack);
		sort_4_a(stack);
		push_a(stack);
	}
	else if (get_position_a(stack, smallest_num) == 2)
	{
		rotate_a(stack);
		swap_a(stack);
		push_b(stack);
		sort_4_a(stack);
		push_a(stack);
	}
	else if (get_position_a(stack, smallest_num) == 3)
	{
		reverse_rotate_a(stack);
		reverse_rotate_a(stack);
		push_b(stack);
		sort_4_a(stack);
		push_a(stack);
	}
	else if (get_position_a(stack, smallest_num) == 4)
	{
		reverse_rotate_a(stack);
		push_b(stack);
		sort_4_a(stack);
		push_a(stack);
	}
}
/*----------------------------------------------------------------------------*/