#include "../push_swap.h"

/*----------------------------------------------------------------------------*/
void	push_rotate_b(t_stack *stack)
{
	if (stack -> base_b[0] <= stack -> piv_small)
	{
		rotate_b(stack);
		stack -> rb++;
	}
	else
	{
		push_a(stack);
		stack -> pa++;
		if (stack -> base_a[0] <= stack -> piv_big)
		{
			rotate_a(stack);
			stack -> ra++;
		}
	}
}

/*----------------------------------------------------------------------------*/
void	back_to_ra(t_stack *stack)
{
	int	rrr;
	int	rem;

	rrr = stack -> rb;
	rem = stack -> ra - rrr;
	while (rrr--)
		reverse_rotate_a_b(stack);
	while (rem--)
		reverse_rotate_a(stack);
}

/*----------------------------------------------------------------------------*/
void	back_to_rb(t_stack *stack)
{
	int	rrr;
	int	rem;

	rrr = stack -> ra;
	rem = stack -> rb - rrr;
	while (rrr--)
		reverse_rotate_a_b(stack);
	while (rem--)
		reverse_rotate_b(stack);
}

/*----------------------------------------------------------------------------*/
void		b_to_a(t_stack *stack, int *cnt)
{
	int	temp;

	(*cnt)++;
	init_value(stack);
	select_pivot_a(stack);
	temp = stack -> len_b;
	while (temp--)
		push_rotate_b(stack);
	a_to_b(stack, cnt);
	if (stack -> ra > stack -> rb)
		back_to_ra(stack);
	else
		back_to_rb(stack);
	a_to_b(stack, cnt);
	b_to_a(stack, cnt);
}

/*----------------------------------------------------------------------------*/