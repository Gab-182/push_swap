/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 02:15:23 by gabdoush          #+#    #+#             */
/*   Updated: 2022/02/21 02:15:38 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*✅-----------------------------------------------------------*/
void	push_swap(char *arg, t_stack *stack)
{
	char	**stack_char;
	int		i;

	i = 0;
	if (!arg)
		exit(EXIT_FAILURE);
	stack_char = ft_split(arg, ' ');
	check_digit(stack_char);
	while (stack_char[i] != NULL)
	{
		if (ft_isdigit(*stack_char[i]))
			i++;
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
}

/*✅-----------------------------------------------------------*/
void	push_swap_multi(char **argv, t_stack *stack)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		check_digit_multi(argv[i]);
		i++;
	}
	stack->base_a = (int *)malloc(sizeof(int) * (i));
	if (!stack->base_a)
		exit(EXIT_FAILURE);
	i = 0;
	while (argv[i])
	{
		stack->base_a[i] = ft_atoi(argv[i]);
		i++;
	}
	stack->len_a = i;
	checking_duplicated(stack);
}

/*======================================================================*/