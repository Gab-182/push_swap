#include "push_swap.h"


void	get_smallest(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack -> base_a[i] != a->sorted[0])
		i++;
	rotate_a_ntimes(a, find_nrotates(i, stack -> len_a));
}

/*----------------------------------------------------------------------------*/
void	get_biggest(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack -> base_a[i] != sorted[stack -> len_a + 1])
		i++;
	rotate_a_ntimes(a, find_nrotates(i, stack -> len_a));
}

/*----------------------------------------------------------------------------*/
void	sort_2(t_stack *stack)
{
	if (stack -> base_a[0] < stack -> base_a[1])
		swap(stack -> base_a[0], stack -> base_a[1]);
}

/*----------------------------------------------------------------------------*/
void	sort_3(t_stack  *stack)
{
	// 2, 1, 3
	if (stack -> base_a[0] > stack -> base_a[1] && stack -> base_a[1] < stack -> base_a[2] && stack -> base_a[0] < stack -> base_a[2])
		swap_a(stack);
	// 2, 3, 1
	else if (stack -> base_a[0] < stack -> base_a[1] && stack -> base_a[1] > stack -> base_a[2] && stack -> base_a[0] > stack -> base_a[2])
		reverse_rotate_a(stack);
	// 3, 2, 1
	else if (stack -> base_a[0] > stack -> base_a[1] && stack -> base_a[1] > stack -> base_a[2] && stack -> base_a[0] > stack -> base_a[2])
	{
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	// 1, 3, 2
	else if (stack -> base_a[0] < stack -> base_a[1] && stack -> base_a[1] > stack -> base_a[2] && stack -> base_a[0] < stack -> base_a[2])
	{
		rotate_a(stack);
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	// 3, 1, 2
	else if (stack -> base_a[0] > stack -> base_a[1] && stack -> base_a[1] < stack -> base_a[2] && stack -> base_a[0] > stack -> base_a[2])
	{
		reverse_rotate_a(stack);
		reverse_rotate_a(stack);
	}
}

/*----------------------------------------------------------------------------*/
void	sort_4(t_stack *stack)
{
	get_smallest(a);
	push_a(stack);
	sort_3(stack);
	push_b(stack);
}

/*----------------------------------------------------------------------------*/
void	sort_5(t_stack *stack)
{

}

/*----------------------------------------------------------------------------*/