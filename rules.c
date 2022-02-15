#include "push_swap.h"

/*-----------------------------------------------------------*/
/**
 ** swap the first 2 elements at the top of stack a. Do nothing if there
 ** is only one or no elements).
 **/
void	swap_a(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->base_a[i] != 0)
		i++;
	if (i > 1)
		swap(&stack->base_a[i - 1], &stack->base_a[i - 2]);
	else
		exit(EXIT_FAILURE);
	/********************************|
	 ********************************|
	 * Testing
	 */
	printf("<<<<<<<<<<<<<<<<  swap_a  >>>>>>>>>>>>>>>>>>>>\n");
	i = 0;
	while (i < stack->len_a)
	{
		printf("base_a[%d] = %d\n", i, stack->base_a[i]);
		i++;
	}
}

/*-----------------------------------------------------------*/
/**
 **  swap the first 2 elements at the top of stack b. Do nothing if there
 ** is only one or no elements).
 **/
void	swap_b(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->base_b[i] != 0)
		i++;
	if (i > 1)
		swap(&stack->base_b[i - 1], &stack->base_b[i - 2]);
	else
		exit(EXIT_FAILURE);
	/********************************|
	 ********************************|
	 * Testing
	 */
	printf("<<<<<<<<<<<<<<<<  swap_b  >>>>>>>>>>>>>>>>>>>>\n");
	i = 0;
	while (i < stack->len_b)
	{
		printf("base_b[%d] = %d\n", i, stack->base_b[i]);
		i++;
	}
}

/*-----------------------------------------------------------*/
/**
 * do swap
 */
void	swap_a_and_b(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
}

/*-----------------------------------------------------------*/
/**
 ** take the first element at the top of a and put it at the top of b. Do
 ** nothing if a is empty.
 **/
void	push_b(t_stack *stack)
{
	int	i;
	if (stack->base_a && stack->len_a)
	{
		printf("<<<<<<<<<<<<<<<<  push_b  >>>>>>>>>>>>>>>>>>>\n");
		/******************************************************************************
		 * Editing stack_b:
		 * 1 - malloc b temp stack according to (len_b + 1).
		 * 2 - edit the len_b to be = len_b + 1.
		 * 3 - copying stack b to temp b.
		 * 4 - free stack_b.
		 * 5 - malloc stack_b agine according to the new length.
		 * 6 - copy the numbers from the temp to the new stack_b.
		 */
		stack->temp_b = (int *)malloc(sizeof(int) * (stack->len_b + 1));
		stack->len_b = stack->len_b + 1;
		i = 0;
		while (i < stack->len_b)
		{
			stack->temp_b[i] = stack->base_b[i];
			i++;
		}
		stack->temp_b[stack->len_b - 1] = stack->base_a[stack->len_a - 1];
		if (stack->len_b > 0)
			free(stack->base_b);
		stack->base_b = (int *)malloc(sizeof(int) * stack->len_b);
		i = 0;
		while (i < stack->len_b)
		{
			stack->base_b[i] = stack->temp_b[i];
			i++;
		}
		free(stack->temp_b);
		/******************************************************************************
		 * Editing stack_a:
		 * 1 - malloc a temp stack according to (len_a - 1).
		 * 2 - edit the len_a to be = len_a - 1.
		 * 3 - copying stack a to stack(temp_a).
		 * 4 - free stack_a.
		 * 5 - malloc stack_a agine according to the new length.
		 * 6 - copy the numbers from the temp to the new stack_a.
		 */
		stack->temp_a = (int *)malloc(sizeof(int) * (stack->len_a - 1));
		stack->len_a = stack->len_a - 1;
		i = 0;
		while (i < stack->len_a)
		{
			stack->temp_a[i] = stack->base_a[i];
			i++;
		}
		if (stack->len_a > 0)
			free(stack->base_a);
		stack->base_a = (int *)malloc(sizeof(int) * stack->len_a);
		i = 0;
		while (i < stack->len_a)
		{
			stack->base_a[i] = stack->temp_a[i];
			i++;
		}
		free(stack->temp_a);

		/******************************************************************************|
		 ******************************************************************************|
		 * Testing:
		 */
		i = 0;
		while (i < stack->len_b)
		{
			printf("base_b[%d] = %d\n", i, stack->base_b[i]);
			i++;
		}
		printf("-----------------------------------\n");
		i = 0;
		while (i < stack->len_a)
		{
			printf("base_a[%d] = %d\n", i, stack->base_a[i]);
			i++;
		}
		/*******************************************************************************/
	}
}

void	push_a(t_stack *stack)
{
	int	i;

	if (stack->base_b && stack->len_b)
	{
		printf("<<<<<<<<<<<<<<<<  push_a  >>>>>>>>>>>>>>>>>>>\n");
		stack->temp_a = (int *)malloc(sizeof(int) * (stack->len_a + 1));
		stack->len_a = stack->len_a + 1;
		i = 0;
		while (i < stack->len_a)
		{
			stack->temp_a[i] = stack->base_a[i];
			i++;
		}
		stack->temp_a[stack->len_a - 1] = stack->base_b[stack->len_b - 1];
		if (stack->len_a > 0)
			free(stack->base_a);
		stack->base_a = (int *)malloc(sizeof(int) * stack->len_a);
		i = 0;
		while (i < stack->len_a)
		{
			stack->base_a[i] = stack->temp_a[i];
			printf("base_a[%d] = %d\n", i, stack->base_a[i]);
			i++;
		}
		free(stack->temp_a);
		printf("----------------------------\n");
		stack->temp_b = (int *)malloc(sizeof(int) * (stack->len_b - 1));
		stack->len_b = stack->len_b - 1;
		i = 0;
		while (i < stack->len_b)
		{
			stack->temp_b[i] = stack->base_b[i];
			i++;
		}
		if (stack->len_b > 0)
			free(stack->base_b);
		stack->base_b = (int *)malloc(sizeof(int) * stack->len_b);
		i = 0;
		while (i < stack->len_b)
		{
			stack->base_b[i] = stack->temp_b[i];
			printf("base_b[%d] = %d\n", i, stack->base_b[i]);
			i++;
		}
		free(stack->temp_b);
	}
}
/*=================================================================================*/