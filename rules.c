#include "push_swap.h"

// /*-----------------------------------------------------------*/
// /**
//  ** swap the first 2 elements at the top of stack a. Do nothing if there
//  ** is only one or no elements).
//  **/
// void	swap_a(t_stack stack_a)
// {
// 	int	i;

// 	i = 0;
// 	while (stack_a.base_a[i] != 0)
// 		i++;
// 	if (i > 1)
// 		swap(&stack_a.base_a[i - 1], &stack_a.base_a[i - 2]);
// 	else
// 		exit(EXIT_FAILURE);
// }

// /*-----------------------------------------------------------*/
// /**
//  **  swap the first 2 elements at the top of stack b. Do nothing if there
//  ** is only one or no elements).
//  **/
// void	swap_b(t_stack stack_b)
// {
// 	int	i;

// 	i = 0;
// 	while (stack_b.base_b[i] != 0)
// 		i++;
// 	if (i > 1)
// 		swap(&stack_b.base_b[i - 1], &stack_b.base_b[i - 2]);
// 	else
// 		exit(EXIT_FAILURE);
// }

// /*-----------------------------------------------------------*/
// /**
//  * do swap
//  */
// void	swap_a_and_b(t_stack stack_a, t_stack stack_b)
// {
// 	swap_a(stack_a);
// 	swap_b(stack_b);
// }

/*-----------------------------------------------------------*/
/**
 ** take the first element at the top of a and put it at the top of b. Do
 ** nothing if a is empty.
 **/
void	push_b(t_stack *stack)
{
	int	i;

	if (stack->base_a != NULL)
	{
		if (stack->len_b == 0)
			stack->temp_b = (int *)malloc(sizeof(int) * 1);
		else
			stack->temp_b = (int *)malloc(sizeof(int) * (stack->len_b + 1));
		stack->len_temp_b += 1;//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		stack->len_b += 1;//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		printf("stack->len_b is %d\n", stack->len_b);
		printf("stack->len_a is %d\n", stack->len_a);
		printf("stack->len_temp_b is %d\n", stack->len_temp_b);

		i = 0;
		while (i <= stack->len_b)
		{
			stack->temp_b[i] = stack->base_b[i];
			i++;
		}
		stack->temp_b[stack->len_temp_b] = stack->base_a[stack->len_a - 1];
		printf("stack->temp_b[stack->len_temp_b] %d\n", stack->temp_b[stack->len_temp_b]);
		/*=========================================================================*/
		if (stack->len_b > 0)
			free(stack->base_b);
		stack->base_b = (int *)malloc(sizeof(int) * stack->len_b);
		/*=========================================================================*/
		printf("========================\n");

		i = 0;
		while (i <= stack->len_b)
		{
			stack->base_b[i] = stack->temp_b[i];
			printf("stack->base_b[%d] ---> %d\n", i, stack->base_b[i]);
			i++;
		}
		/*=========================================================================*/
		if (stack->len_temp_b > 0)
			free(stack->temp_b);
		/*=========================================================================*/
		if (stack->len_temp_a)
			free(stack->temp_a);
		/*=========================================================================*/
		stack->temp_a = (int *)malloc(sizeof(int) * stack->len_a - 1);
		stack->len_a -= 1;//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

		/*=========###Copying to the temp_a from base_a to temp_a###===============*/
		printf("========================\n");

		i = 0;
		while (i <= stack->len_a - 1)
		{
			stack->temp_a[i] = stack->base_a[i];
			printf("asdstack->temp_a[%d] ---> %d\n", i, stack->temp_a[i]);
			i++;
		}
		/*========================#### Free base_a ####=============================*/
		if (stack->len_a > 0)
			free(stack->base_a);
		/*===========#malloc base_a agine after removing the pushed number#=========*/
		stack->base_a = (int *)malloc(sizeof(int) * (stack->len_a - 1));
		//stack->len_a = stack->len_a - 1;
		printf("========================\n");
		i = 0;
		while (i <= stack->len_a)
		{
			stack->base_a[i] = stack->temp_a[i];
			printf("stack->base_a[%d] ---> %d\n", i, stack->base_a[i]);
			i++;
		}
		/*=========================================================================*/
		if (stack->len_temp_a > 0)
			free(stack->temp_a);
		/*=========================================================================*/
	}
	/*====================##### JUST PRINTING #####==========================*/
	// i = 0;
	// while (i <= stack->len_b)
	// {
	// 	printf("stack_b[%d] ---> %d\n", i, stack->base_b[i]);
	// 	i++;
	// }
	// printf("/-------------------------\\\n");
}

/*=================================================================================*/