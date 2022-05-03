#include "../push_swap.h"

/*============================================================================*/
int	small_chunks_a(int size, t_stack *stack)
{
	if (size == 1 || size == 0)
		return (0);
	else if (size == 2)
	{
		sort_2_a(stack);
		return (0);
	}
	if (size == 3)
	{
		sort_chunk_3_a(3, stack);
		return (0);
	}
	else if(size == 4)
	{
		sort_4_a(4, stack);
		return (0);
	}
	else if (size == 5)
	{
		sort_chunk_5_a(5, stack);
		return (0);
	}
	else
		return (1);
}

/*----------------------------------------------------------------------------*/
/** _______________
 **| EXPLANATION: |
 **---------------
 * so the logic here is to check if the first number in the stack is bigger or
 * smaller than the (big pivot):
 * --> if it is bigger --> rotate the stack_a.
 * --> if it is smaller --> push the number to the stack b.
 * then comapare the pushed number with the small pivot:
 * --> if it is bigger --> rotate stack_b
 **/

/**
 * @brief if the first numbers in the stack _a bigger than the (big pivot) 
 * push it to the stack_b, else rotate the stack_a.
 * 
 * @param stack 
 */
void	compare_to_pivot(t_stack *stack, t_rules *rules)
{
	if (stack -> base_a[0] > rules-> piv_big)
	{
		rotate_a(stack);
		ft_putstr("ra\n");
		rules -> ra++;
	}
	else
	{
		push_b(stack);
		ft_putstr("pb\n");
		rules -> pb++;
		if (stack -> base_b[0] > rules -> piv_small)
		{
			rotate_b(stack);
			ft_putstr("rb\n");
			rules -> rb++;
		}
	}
}

/*----------------------------------------------------------------------------*/
void	back_to_orig_ra(t_stack *stack, int *cnt, t_rules *rules)
{
	int	rrr;
	int	rem;

	rrr = rules -> rb;
	rem = rules -> ra - rrr;
	if ((*cnt) > 0)
	{
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
	else // to move the biggest number of b to the top.
	{
		while (rrr--)
		{
			reverse_rotate_b(stack);
			ft_putstr("rrb\n");
		}
	}
}

/*----------------------------------------------------------------------------*/
void	back_to_orig_rb(t_stack *stack, int *cnt, t_rules *rules)
{
	int	rrr;
	int	rem;

	rrr = rules -> ra;
	rem = rules -> rb - rrr;
	if ((*cnt) > 0)
	{
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
	else
	{
		rrr = rules -> rb;
		while (rrr--)
		{
			reverse_rotate_b(stack);
			ft_putstr("rrb\n");
		}
	}
}

/*----------------------------------------------------------------------------*/
void		a_to_b(int size, t_stack *stack, int *cnt)
{
	int	temp;
	t_rules rules;

	if (!small_chunks_a(size, stack))
		return ;
	init_value(&rules);
	select_pivot(size, stack -> base_a, &rules);
	temp = size;
	while (temp--)
		compare_to_pivot(stack, &rules);
	/** _______________
	 **| EXPLANATION: |
	 **---------------
	 * ra --> represent how many numbers in stack a bigger that the big pivot.
	 * rb --> represent how many numbers in stack b bigger that the small pivot.
	 * So here we are comparing how many numbers in stack_a bigger than pivot_big,
	 * with how many numbers from stack_b bigger than pivot_small.
	*/
	if (rules.ra > rules.rb)
		back_to_orig_ra(stack, cnt, &rules);
	else
		back_to_orig_rb(stack, cnt, &rules);
	/** _______________
	 **| EXPLANATION: |
	 **---------------
	 * then do recursive for the function, but now the size is taken
	 * according to how many times we rotate the stack a.
	 * that mean call the function with the the length of the rest of the 
	 * numbers that left in the stack and those numbers are bigger than
	 * the (pivot_big).
	 **/
	a_to_b(rules.ra, stack, cnt); // call again for (ra) the rest of the number in stack_a.
	b_to_a(rules.rb, stack, cnt);
	b_to_a(rules.pb - rules.rb, stack, cnt);
}

/*============================================================================*/