/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:19:29 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/10 03:42:06 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			error_with_free_2d(stack_char);
	}
	if (i == 1 && (ft_atoi(stack_char[0]) > 2147483647 || \
		ft_atoi(stack_char[0]) < -2147483648))
		error_with_free_2d(stack_char);
	if (i == 1 || i == 0)
	{
		free_2d(stack_char);
		exit(EXIT_SUCCESS);
	}
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
	free_2d(stack_char);
	stack->len_a = i;
	checking_duplicated(stack);
	sort(stack -> len_a, stack);
}

/*✅-------------------------------------------------------------------------*/
/**
 * @brief 😒😒😒Helper function for push_swap_multi {just for Norm 😒😒😒 }
 * 
 * @param argv 
 * @param stack 
 * @param i 
 */
int	store_to_stack(char **argv, t_stack *stack, int i)
{
	int	num;

	if (argv[i])
	{
		check_digit_multi(argv[i]);
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			free_stack(stack->base_a, '1');
		num = ft_atoi(argv[i]);
		add_last(stack, num);
		i++;
	}
	return (i);
}

/*✅-------------------------------------------------------------------------*/
/**
 * @brief 😒😒😒Helper function for push_swap_multi {just for Norm 😒😒😒 }
 * 
 * @param argv 
 * @param stack 
 * @param i 
 */
void	deal_with_spaces(char **argv, t_stack *stack, int i)
{
	int		s;
	int		num;
	char	**split;

	s = 0;
	split = ft_split(argv[i], ' ');
	while (split[s])
	{
		num = ft_atoi(split[s]);
		free(split[s]);
		add_last(stack, num);
		s++;
	}
	free(split);
	split = NULL;
}

/*✅-------------------------------------------------------------------------*/
/**
 ** @brief handle parsing and sorting for multiple arguments
 ** @param argv 
 ** @param stack
 **/
void	push_swap_multi(char **argv, t_stack *stack)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		check_empty(argv[i]);
		check_negative_sign(argv);
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
			{
				deal_with_spaces(argv, stack, i);
				i++;
				j = 0;
				break ;
			}
			else
				j++;
		}
		i = store_to_stack(argv, stack, i);
	}
}

/*============================================================================*/