#include "../push_swap.h"

int	exceptional_cases_b(int size, t_stack *stack)
{
	if (size == 1)
	{
		push_a(stack);
		ft_putstr("pa\n");
		return (0);
	}
	if (size == 2)
	{
		sort_2_b(stack);
		return (0);
	}
	else if (size == 3)
	{
		sort_3_b(stack);
		return (0);
	}
	else if (size == 4)
	{
		sort_4_b(stack);
		return (0);
	}
	else if (size == 5)
	{
		sort_5_b(stack);
		return (0);
	}
	else
		return (1);
}
/*----------------------------------------------------------------------------*/
void	push_rotate_b(t_stack *stack)
{
	if (stack -> base_b[0] <= stack -> piv_small)
	{
		rotate_b(stack);
		ft_putstr("rb\n");
		stack -> rb++;
	}
	else
	{
		push_a(stack);
		ft_putstr("pa\n");
		stack -> pa++;
		if (stack -> base_a[0] <= stack -> piv_big)
		{
			rotate_a(stack);
			ft_putstr("ra\n");
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
	{
		reverse_rotate_a_b(stack);
		ft_putstr("rrr\n");
	}
	while (rem--)
	{
		reverse_rotate_a(stack);
		ft_putstr("rra\n");
	}
}

/*----------------------------------------------------------------------------*/
void	back_to_rb(t_stack *stack)
{
	int	rrr;
	int	rem;

	rrr = stack -> ra;
	rem = stack -> rb - rrr;
	while (rrr--)
	{
		reverse_rotate_a_b(stack);
		ft_putstr("rrr\n");
	}
	while (rem--)
	{
		reverse_rotate_b(stack);
		ft_putstr("rrb\n");
	}
}

/*----------------------------------------------------------------------------*/
void	b_to_a(int size, t_stack *stack, int *cnt)
{
	int	temp;

	if (!exceptional_cases_b(size, stack))
		return ;
	(*cnt)++;
	init_value(stack);
	select_pivot_b(stack);
	temp = size;
	while (temp--)
		push_rotate_b(stack);
	a_to_b(stack -> pa - stack -> ra, stack, cnt);
	if (stack -> ra > stack -> rb)
		back_to_ra(stack);
	else
		back_to_rb(stack);
	a_to_b(stack -> ra, stack, cnt);
	b_to_a(stack -> rb, stack, cnt);
}

/*----------------------------------------------------------------------------*/