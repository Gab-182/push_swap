#include "push_swap.h"

/*✅---------------------------------------------------------------------------*/
void	push_swap(char *arg, t_stack *stack)
{
	char	**stack_char;
	int		i;

	i = 0;
	if (!arg)
		exit(EXIT_FAILURE);
	check_empty(arg);
	stack_char = ft_split(arg, ' ');
	check_digit(stack_char);
	while (stack_char[i])
	{
		if ((*stack_char[i] >= '0' && *stack_char[i] <= '9') || *stack_char[i] == '-' || *stack_char[i] == ' ' || *stack_char[i] == '+')
			i++;
		else
			error();
	}
	stack->base_a = (int *)malloc(sizeof(int) * (i));
	if (!stack->base_a)
		exit(EXIT_FAILURE);
	i = 0;
	while (stack_char[i])
	{
		stack->base_a[i] = ft_atoi(stack_char[i]);
		i++;
	}
	stack->len_a = i;
	checking_duplicated(stack);
	
	// /*🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡*/
	// /*🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡 BUBBLE SORTING 🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡*/
	// /*🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡🁡*/
	// int n = stack->len_a;

	// bubble_sort (stack->base_a, n);
	// for (i = 0; i < n; i++)
	// {
	// 	printf("%d%s", stack->base_a[i], i == n - 1 ? "\n" : " ");
	// }
}

/*✅---------------------------------------------------------------------------*/
void	push_swap_multi(char **argv, t_stack *stack, int i)
{
	while (argv[i] != NULL)
	{
		check_length(argv[i]);
		check_digit_multi(argv[i]);
		i++;
	} 
	//stack->base_a = (int *)malloc(sizeof(int) * (i));
	if (!stack->base_a)
		exit(EXIT_FAILURE);
	i = 0;
	while (argv[i])
	{
		stack->base_a[i] = ft_atoi(argv[i]);
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
		{
			free(stack->base_a);
			error();
		}
		i++;
	}
	stack->len_a = i;
	checking_duplicated(stack);
}

/*=============================================================================*/