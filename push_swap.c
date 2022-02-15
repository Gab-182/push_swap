#include "push_swap.h"

/*------------------------------------------------------*/

void	push_swap(char *arg, t_stack *stack)
{
	char	**stack_char;
	int		i;
	
	i = 0;
	if (!arg)
		exit(EXIT_FAILURE);
	stack_char = ft_split(arg, ' ');
/*---------------------------------------*/
/*Checking If all the elements are digits*/
/*========================================*/
	check_digit(stack_char);
/*========================================*/
/* Calculating the length of the string  */
/*========================================*/
	while (stack_char[i] != NULL)
	{
		if (ft_isdigit(*stack_char[i]))
			i++;
	}
	stack->base_a = (int *)malloc(sizeof(int) * (i));
	i = 0;
/*========================================*/
/* Storing the integers inside that array */
/*========================================*/
	while (stack_char[i])
	{
		stack->base_a[i] = ft_atoi(stack_char[i]);
		i++;
	}
	stack->len_a = i;
/*==============================*/
/* checking duplicated elements */
/*==============================*/
	checking_duplicated(stack);
/*------------------------------------------------------*/
	push_b(stack);
	push_b(stack);
	push_b(stack);

	push_a(stack);
	
	swap_b(stack);
	swap_a(stack);
}
