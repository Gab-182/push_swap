#include "../push_swap.h"

/*----------------------------------------------------------------------------*/
void	push_rotate_a(t_stack *stack)
{
	if (stack -> base_a[0] > stack-> piv_big)
	{
		rotate_a(stack);
		stack -> ra++;
	}
	else
	{
		push_b(stack);
		stack -> pb++;
		if (stack -> base_b[0] > stack -> piv_small)
		{
			rotate_b(stack);
			stack -> rb++;
		}
	}
}

/*----------------------------------------------------------------------------*/
void	back_to_orig_ra(t_stack *stack, int *cnt)
{
	int	rrr;
	int	rem;

	rrr = stack -> rb;
	rem = stack -> ra - rrr;
	if ((*cnt) > 0)
	{
		while (rrr--)
			reverse_rotate_a_b(stack);
		while (rem--)
			reverse_rotate_a(stack);
	}
	else
	{
		while (rrr--)
			reverse_rotate_b(stack);
	}
}

/*----------------------------------------------------------------------------*/
void	back_to_orig_rb(t_stack *stack, int *cnt)
{
	int	rrr;
	int	rem;

	rrr = stack -> ra;
	rem = stack -> rb - rrr;
	if ((*cnt) > 0)
	{
		while (rrr--)
			reverse_rotate_a_b(stack);
		while (rem--)
			reverse_rotate_b(stack);
	}
	else
	{
		rrr = stack -> rb;
		while (rrr)
		{
			reverse_rotate_b(stack);
			rrr--;
		}
	}
}

/*----------------------------------------------------------------------------*/
void		a_to_b(t_stack *stack, int *cnt)
{
	int		temp;

	init_value(stack);
	select_pivot_a(stack);
	temp = stack -> len_a;
	while (temp >= 0)
	{
		push_rotate_a(stack);
		temp--;
	}
		
	if (stack -> ra > stack -> rb)
		back_to_orig_ra(stack, cnt);
	else
		back_to_orig_rb(stack, cnt);
	a_to_b(stack, cnt);
	b_to_a(stack, cnt);
	b_to_a(stack, cnt);
}

/*----------------------------------------------------------------------------*/