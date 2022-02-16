#include "push_swap.h"

/*✅-----------------------------------------------------------*/
void	swap_a(t_stack *stack)
{
	int	i;

	if (stack->len_a > 1)
		swap(&stack->base_a[0], &stack->base_a[1]);
	else
		exit(EXIT_FAILURE);
	/********************************|
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

/*✅-----------------------------------------------------------*/
void	swap_b(t_stack *stack)
{
	//int	i;

	if (stack->len_b > 1)
		swap(&stack->base_b[0], &stack->base_b[1]);
	else
		exit(EXIT_FAILURE);
	/********************************|
	 ********************************|
	 * Testing
	 */
	// printf("<<<<<<<<<<<<<<<<  swap_b  >>>>>>>>>>>>>>>>>>>>\n");
	// i = 0;
	// while (i < stack->len_b)
	// {
	// 	printf("base_b[%d] = %d\n", i, stack->base_b[i]);
	// 	i++;
	// }
}

/*✅-----------------------------------------------------------*/
void	swap_a_and_b(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
}

/*✅-----------------------------------------------------------*/
void	push_b(t_stack *stack)
{
	int	i;

	if (stack->base_a && stack->len_a)
	{
		printf("<<<<<<<<<<<<<<<<  push_b  >>>>>>>>>>>>>>>>>>>\n");
		stack->temp_b = (int *)malloc(sizeof(int) * (stack->len_b + 1));
		stack->len_b = stack->len_b + 1;
		i = 0;
		while (i < stack->len_b - 1 && stack->len_b > 1)
		{
			stack->temp_b[i + 1] = stack->base_b[i];
			i++;
		}
		stack->temp_b[0] = stack->base_a[0];
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
/*******************************************************************************/
		stack->temp_a = (int *)malloc(sizeof(int) * (stack->len_a - 1));
		stack->len_a = stack->len_a - 1;
		i = 0;
		while (i < stack->len_a)
		{
			stack->temp_a[i] = stack->base_a[i + 1];
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
		 * Testing:
		 */
		// i = 0;
		// while (i < stack->len_b)
		// {
		// 	printf("base_b[%d] = %d\n", i, stack->base_b[i]);
		// 	i++;
		// }
		// printf("-----------------------------------\n");
		// i = 0;
		// while (i < stack->len_a)
		// {
		// 	printf("base_a[%d] = %d\n", i, stack->base_a[i]);
		// 	i++;
		// }
		/*******************************************************************************/
	}
}

/*✅-----------------------------------------------------------*/
void	push_a(t_stack *stack)
{
		int	i;

	if (stack->base_b && stack->len_b)
	{
		printf("<<<<<<<<<<<<<<<<  push_a  >>>>>>>>>>>>>>>>>>>\n");
		stack->temp_a = (int *)malloc(sizeof(int) * (stack->len_a + 1));
		stack->len_a = stack->len_a + 1;
		i = 0;
		while (i < stack->len_a - 1 && stack->len_a > 1)
		{
			stack->temp_a[i + 1] = stack->base_a[i];
			i++;
		}
		stack->temp_a[0] = stack->base_b[0];
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
/*******************************************************************************/
		stack->temp_b = (int *)malloc(sizeof(int) * (stack->len_b - 1));
		stack->len_b = stack->len_b - 1;
		i = 0;
		while (i < stack->len_b)
		{
			stack->temp_b[i] = stack->base_b[i + 1];
			i++;
		}
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

		/******************************************************************************|
		 * Testing:
		 */
		// i = 0;
		// while (i < stack->len_a)
		// {
		// 	printf("base_a[%d] = %d\n", i, stack->base_a[i]);
		// 	i++;
		// }
		// printf("-----------------------------------\n");
		// i = 0;
		// while (i < stack->len_b)
		// {
		// 	printf("base_b[%d] = %d\n", i, stack->base_b[i]);
		// 	i++;
		// }
		/*******************************************************************************/
	}
}

/*✅-----------------------------------------------------------*/
void	rotate_a(t_stack *stack)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	stack->temp_a = (int *)malloc(sizeof(int) * stack->len_a);
	while (i < stack->len_a)
	{
		stack->temp_a[j] = stack->base_a[i];
		i++;
		j++;
	}
	stack->temp_a[stack->len_a - 1] = stack->base_a[0];
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
	 * Testing:
	 */
	i = 0;
	while (i < stack->len_a)
	{
		printf("base_a[%d] = %d\n", i, stack->base_a[i]);
		i++;
	}
	/*******************************************************************************/

}

/*✅-----------------------------------------------------------*/
void	rotate_b(t_stack *stack)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	stack->temp_b = (int *)malloc(sizeof(int) * stack->len_b);
	while (i < stack->len_b)
	{
		stack->temp_b[j] = stack->base_b[i];
		i++;
		j++;
	}
	stack->temp_b[stack->len_b - 1] = stack->base_b[0];
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
	/******************************************************************************|
	 * Testing:
	 */
	i = 0;
	while (i < stack->len_b)
	{
		printf("base_b[%d] = %d\n", i, stack->base_b[i]);
		i++;
	}
	/*******************************************************************************/

}

/*✅-----------------------------------------------------------*/
void	rotate_a_b(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
}

/*✅-----------------------------------------------------------*/
void	reverse_rotate_a(t_stack *stack)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	stack->temp_a = (int *)malloc(sizeof(int) * stack->len_a);
	while (i < stack->len_a)
	{
		stack->temp_a[i] = stack->base_a[j];
		i++;
		j++;
	}
	stack->temp_a[0] = stack->base_a[stack->len_a - 1];
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
	 * Testing:
	 */
	i = 0;
	while (i < stack->len_a)
	{
		printf("base_a[%d] = %d\n", i, stack->base_a[i]);
		i++;
	}
	/*******************************************************************************/

}

/*✅-----------------------------------------------------------*/

void	reverse_rotate_b(t_stack *stack)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	stack->temp_b = (int *)malloc(sizeof(int) * stack->len_b);
	while (i < stack->len_b)
	{
		stack->temp_b[i] = stack->base_b[j];
		i++;
		j++;
	}
	stack->temp_b[0] = stack->base_b[stack->len_b - 1];
	i = 0;
	while (i < stack->len_b)
	{
		stack->base_b[i] = stack->temp_b[i];
		i++;
	}
	free(stack->temp_b);
	/******************************************************************************|
	 * Testing:
	 */
	i = 0;
	while (i < stack->len_b)
	{
		printf("temp_b[%d] = %d\n", i, stack->temp_b[i]);
		i++;
	}
	/*******************************************************************************/

}

/*✅-----------------------------------------------------------*/
void	reverse_rotate_a_b(t_stack *stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
}

/*=================================================================================*/