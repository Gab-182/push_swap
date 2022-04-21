#include "../push_swap.h"

/*----------------------------------------------------------------------------*/
/**
 * @brief Sorting two numbers in stack b.
 * @param stack 
 */
void	sort_2_b(t_stack *stack)
{
	if (stack -> base_b[1] > stack -> base_b[0])
		swap_b(stack);
	push_a(stack);
	push_a(stack);
}

/*----------------------------------------------------------------------------*/
/**
 * @brief Sorting 3 numbers in stack b.
 * @param stack 
 */
void	sort_3_b(t_stack  *stack)
{
	int	largest_num;

	largest_num = get_largest_b(stack);
	// 3 1 2
	if (get_position_b(stack, largest_num) == 0)
	{
		push_a(stack);
		sort_2_b(stack);
	}
	// 1 3 2
	else if (get_position_b(stack, largest_num) == 1)
	{
		swap_b(stack);
		push_a(stack);
		sort_2_b(stack);
	}
	// 2 1 3
	else if (get_position_b(stack, largest_num) == 2)
	{
		reverse_rotate_b(stack);
		push_a(stack);
		sort_2_b(stack);
	}
}

/*----------------------------------------------------------------------------*/
/**
 * @brief Sorting 4 numbers in stack b.
 * @param stack 
 */
void	sort_4_b(t_stack *stack)
{
	int	largest_num;

	largest_num = get_largest_b(stack);
	// 4 2 3 1
	if (get_position_b(stack, largest_num) == 0)
	{
		push_a(stack);
		sort_3_b(stack);
	}
	// 2 4 3 1
	else if (get_position_b(stack, largest_num) == 1)
	{
		swap_b(stack);
		push_a(stack);
		sort_3_b(stack);

	}
	// 2 3 4 1
	else if (get_position_b(stack, largest_num) == 2)
	{
		rotate_b(stack);
		swap_b(stack);
		push_a(stack);
		sort_3_b(stack);

	}
	// 2 3 1 4
	else if (get_position_b(stack, largest_num) == 3)
	{
		reverse_rotate_b(stack);
		push_a(stack);
		sort_3_b(stack);
	}
}

/*----------------------------------------------------------------------------*/
/**
 * @brief Sorting 5 numbers in stack b.
 * @param stack 
 */
void	sort_5_b(t_stack *stack)
{
	int	largest_num;

	largest_num = get_largest_b(stack);
	// 5 3 4 2 1
	if (get_position_b(stack, largest_num) == 0)
	{
		push_a(stack);
		sort_4_b(stack);
	}
	// 3 5 4 2 1
	else if (get_position_b(stack, largest_num) == 1)
	{
		swap_b(stack);
		push_a(stack);
		sort_4_b(stack);
	}
	// 3 4 5 2 1
	else if (get_position_b(stack, largest_num) == 2)
	{
		rotate_b(stack);
		swap_b(stack);
		push_a(stack);
		sort_4_b(stack);
	}
	// 3 4 2 5 1
	else if (get_position_b(stack, largest_num) == 3)
	{
		reverse_rotate_b(stack);
		reverse_rotate_b(stack);
		push_a(stack);
		sort_4_b(stack);
	}
	// 3 4 2 1 5
	else if (get_position_b(stack, largest_num) == 4)
	{
		reverse_rotate_b(stack);
		push_a(stack);
		sort_4_b(stack);
	}
}
/*----------------------------------------------------------------------------*/