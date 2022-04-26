#include "push_swap.h"

void	sort(int size, t_stack *stack)
{
	int	cnt;

	cnt = 0;
	if (is_sorted(stack) == 1)
	{
		if (stack -> len_a == 2)
			sort_2_a(stack);
		else if (stack -> len_a == 3)
			sort_3_a(stack);
		else if (stack -> len_a == 4)
			sort_4_a(size, stack);
		else if (stack -> len_a == 5)
			sort_5_a(size, stack);
		else if (stack -> len_a > 5)
			a_to_b(size, stack, &cnt);
	}
}

/*✅-------------------------------------------------------------------------*/
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
	while (stack_char[i] != NULL)
	{
		if ((*stack_char[i] >= '0' && *stack_char[i] <= '9') || \
			*stack_char[i] == '-' || *stack_char[i] == ' ' \
			|| *stack_char[i] == '+')
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
	/************************   SORTING  **************************************/

	sort(stack -> len_a, stack);
	printf("-----------------------\n");
	printf("Rules number = %d\n", stack -> rules_number);
	printf("-----------------------\n");
	i = 0;
	printf("After sorting :\n");
	while(i < stack -> len_a)
	{
		printf("stack -> base_a[%d] = %d\n", i, stack -> base_a[i]);
		i++;
	}
	printf("-----------------------\n");
}

/*----------------------------------------------------------------------------*/
void	push_swap_multi(char **argv, t_stack *stack)
{
	int			i;
	int			j;
	int			s;
	int			num;
	char		**split;

	i = 0;
	j = 0;
	s = 0;
	while (argv[i])
	{
		check_empty(argv[i]);
		check_negative_sign(argv[i]);
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
			{
				split = ft_split(argv[i], ' ');
				while (split[s])
				{
					num = ft_atoi(split[s]);
					addLast(stack,num);
					s++;
				}
				free(split);
				split = NULL;
				i++;
				j = 0;
				break ;
			}
			else
				j++;
		}
		j = 0;
		if (argv[i])
		{
			check_digit_multi(argv[i]);
			if(ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
				error();
			num = ft_atoi(argv[i]);
			addLast(stack,num);
			i++;
		}
	}
	checking_duplicated(stack);
	/************************   SORTING  **************************************/

	sort(stack -> len_a, stack);
	printf("-----------------------\n");
	printf("Rules number = %d\n", stack -> rules_number);
	printf("-----------------------\n");
	i = 0;
	while(i < stack -> len_a)
	{
		printf("base_a[%d] = %d\n", i, stack -> base_a[i]);
		i++;
	}
	printf("-----------------------\n");


	printf("-----------------------\n");
	i = 0;
	while(i < stack -> len_b)
	{
		printf("base_b[%d] = %d\n", i, stack -> base_b[i]);
		i++;
	}
	printf("-----------------------\n");
}
/*============================================================================*/
