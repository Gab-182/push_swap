#include "../push_swap.h"

int	exceptional_cases_a(int size, t_stack *stack)
{
	if (size == 1)
		return (0);
	if (size == 2)
	{
		sort_2_a(stack);
		return (0);
	}
	else if (size == 3)
	{
		sort_3_a(stack);
		return (0);
	}
	else if (size == 4)
	{
		sort_4_a(stack);
		return (0);
	}
	else if (size == 5)
	{
		sort_5_a(stack);
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
void	compare_to_pivot(t_stack *stack)
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
		{
			reverse_rotate_a_b(stack);
			// rrr--;
		}
		while (rem--)
		{
			reverse_rotate_a(stack);
			// rem--;
		}
	}
	else
	{
		while (rrr--)
		{
			reverse_rotate_b(stack);
			// rrr--;
		}
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
		{
			reverse_rotate_a_b(stack);
			// rrr--;
		}
		while (rem--)
		{
			reverse_rotate_b(stack);
			// rem--;
		}
	}
	else
	{
		rrr = stack -> rb;
		while (rrr--)
		{
			reverse_rotate_b(stack);
			// rrr--;
		}
	}
}

/*----------------------------------------------------------------------------*/
void		a_to_b(int size, t_stack *stack, int *cnt)
{
	int	temp;

	if (!exceptional_cases_a(size, stack))
		return ;
	init_value(stack);
	select_pivot_a(stack);
	temp = size;
	while (temp--)
	{
		compare_to_pivot(stack);
		// temp--;
	}
	/***
	 * ra --> represent how many numbers in stack a bigger that the big pivot.
	 * rb --> represent how many numbers in stack b bigger that the small pivot.
	 * So here we are comparing how many numbers in stack_a bigger than pivot_big,
	 * with how many numbers from stack_b bigger than pivot_small.
	*/
	if (stack -> ra > stack -> rb)
		back_to_orig_ra(stack, cnt);
	else
		back_to_orig_rb(stack, cnt);
	/** _______________
	 **| EXPLANATION: |
	 **---------------
	 * then do recursive for the function, but now the size is taken
	 * according to how many times we rotate the stack a.
	 * that mean call the function with the the length of the rest of the 
	 * numbers that left in the stack and those numbers are bigger than
	 * the (pivot_big).
	 **/
	a_to_b(stack -> ra, stack, cnt);
	b_to_a(stack -> rb, stack, cnt);
	b_to_a(stack -> pb - stack -> rb, stack, cnt);
}

/*----------------------------------------------------------------------------*/