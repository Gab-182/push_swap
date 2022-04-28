#include "../push_swap.h"

/*----------------------------------------------------------------------------*/
/**
 * @brief Sorting two numbers in stack a.
 * @param stack 
 */
void	sort_2_a(t_stack *stack)
{
	if (stack -> base_a[1] < stack -> base_a[0])
	{
		swap_a(stack);
		ft_putstr("sa\n");
	}
}

/*----------------------------------------------------------------------------*/
/**
 * @brief Sorting 4 numbers in stack a according to the smaller number position
 * in the stack a.
 * 
 * @param size 
 * @param chunk 
 * @param stack 
 */
void	sort_4_a(int size, t_stack *stack)
{
	int	smallest_num;

	smallest_num = get_smallest(size, stack -> base_a);
	if (get_position(size, smallest_num, stack -> base_a) == 0)
	{
		push_b(stack);
		ft_putstr("pb\n");
		sort_chunk_3_a(size, stack);
		push_a(stack);
		ft_putstr("pa\n");
	}
	else if (get_position(size, smallest_num, stack -> base_a) == 1)
	{
		swap_a(stack);
		ft_putstr("sa\n");
		push_b(stack);
		ft_putstr("pb\n");
		sort_chunk_3_a(size, stack);
		push_a(stack);
		ft_putstr("pa\n");
	}
	else if (get_position(size, smallest_num, stack -> base_a) == 2)
	{
		rotate_a(stack);
		ft_putstr("ra\n");
		swap_a(stack);
		ft_putstr("sa\n");
		push_b(stack);
		ft_putstr("pb\n");
		sort_chunk_3_a(size, stack);
		push_a(stack);
		ft_putstr("pa\n");
	}
	else if (get_position(size, smallest_num, stack -> base_a) == 3)
	{
		reverse_rotate_a(stack);
		ft_putstr("rra\n");
		push_b(stack);
		ft_putstr("pb\n");
		sort_chunk_3_a(size, stack);
		push_a(stack);
		ft_putstr("pa\n");
	}
}

/*----------------------------------------------------------------------------*/
/**
 * @brief Sorting 5 numbers in stack a according to the smaller number position
 * in the stack a.
 * 
 * @param size 
 * @param chunk 
 * @param stack 
 */
void	sort_5_a(int size, t_stack *stack)
{
	int	smallest_num;

	smallest_num = get_smallest(size, stack -> base_a);
	if (get_position(size, smallest_num, stack -> base_a) == 0)
	{
		push_b(stack);
		ft_putstr("pb\n");
		sort_4_a(size, stack);
		push_a(stack);
		ft_putstr("pa\n");
	}
	else if (get_position(size, smallest_num, stack -> base_a) == 1)
	{
		swap_a(stack);
		ft_putstr("sa\n");
		push_b(stack);
		ft_putstr("pb\n");
		sort_4_a(size, stack);
		push_a(stack);
		ft_putstr("pa\n");
	}
	else if (get_position(size, smallest_num, stack -> base_a) == 2)
	{
		rotate_a(stack);
		ft_putstr("ra\n");
		swap_a(stack);
		ft_putstr("sa\n");
		push_b(stack);
		ft_putstr("pb\n");
		sort_4_a(size, stack);
		push_a(stack);
		ft_putstr("pa\n");
	}
	else if (get_position(size, smallest_num, stack -> base_a) == 3)
	{
		reverse_rotate_a(stack);
		reverse_rotate_a(stack);
		ft_putstr("rra\nrra\n");
		push_b(stack);
		ft_putstr("pb\n");
		sort_4_a(size, stack);
		push_a(stack);
		ft_putstr("pa\n");
	}
	else if (get_position(size, smallest_num, stack -> base_a) == 4)
	{
		
		reverse_rotate_a(stack);
		ft_putstr("rra\n");
		push_b(stack);
		ft_putstr("pb\n");
		sort_4_a(size, stack);
		push_a(stack);
		ft_putstr("pa\n");
	}
}
/*----------------------------------------------------------------------------*/