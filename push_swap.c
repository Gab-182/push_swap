/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:19:29 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/05 13:19:40 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 ** @brief the main part of the sort algorithem, it handle all of the sizes
 ** @param size 
 ** @param stack 
 **/
void	sort(int size, t_stack *stack)
{
	int	cnt;

	cnt = 0;
	if (is_sorted(stack) == 1)
	{
		if (stack -> len_a == 2)
			sort_2_a(stack);
		else if (stack -> len_a == 3)
			sort_chunk_3_a(3, stack);
		else if (stack -> len_a == 4)
			sort_4_a(4, stack);
		else if (stack -> len_a == 5)
			sort_5_a(5, stack);
		else if (stack -> len_a > 5)
			a_to_b(size, stack, &cnt);
	}
	else
	{
		free(stack -> base_a);
		exit (0);
	}
}

/*✅-------------------------------------------------------------------------*/
/**
 ** @brief helper function to calculate the length of a 2d string to use it in
 ** ft_calloc in push_swap().
 ** @param stack_char 
 ** @return int 
 **/
int	ft_get_length(char **stack_char)
{
	int	i;

	i = 0;
	while (stack_char[i] != NULL)
	{
		if ((*stack_char[i] >= '0' && *stack_char[i] <= '9') || \
			*stack_char[i] == '-' || *stack_char[i] == ' ' \
			|| *stack_char[i] == '+')
			i++;
		else
			error();
	}
	if (i == 1 || i == 0)
		exit(EXIT_SUCCESS);
	return (i);
}

/*✅-------------------------------------------------------------------------*/
/**
 ** @brief handle the parsing and sorting for single argument.
 ** @param arg 
 ** @param stack 
 **/
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
	i = ft_get_length(stack_char);
	stack->base_a = ft_calloc(sizeof(int), (i));
	if (!stack -> base_a)
		free_stack(stack -> base_a, 'e');
	i = 0;
	while (stack_char[i])
	{
		stack->base_a[i] = ft_atoi(stack_char[i]);
		i++;
	}
	stack->len_a = i;
	checking_duplicated(stack);
	sort(stack -> len_a, stack);
}

/*----------------------------------------------------------------------------*/
/**
 ** @brief handle parsing and sorting for multiple arguments
 ** @param argv 
 ** @param stack 
 **/
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
					add_last(stack, num);
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
			if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
				error();
			num = ft_atoi(argv[i]);
			add_last(stack, num);
			i++;
		}
	}
	checking_duplicated(stack);
	sort(stack -> len_a, stack);
/************************   PRINTING  **************************************/
	printf("\n============  a  ================= \n");
	i = 0;
	while (i < stack -> len_a)
	{
		printf("%d\n", stack -> base_a[i]);
		i++;
	}
	printf("\n============  b  ================= \n");
	i = 0;
	while (i < stack -> len_b)
	{
		printf("%d ", stack -> base_b[i]);
		i++;
	}
}

/*============================================================================*/