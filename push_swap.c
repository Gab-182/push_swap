/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:04:52 by gabdoush          #+#    #+#             */
/*   Updated: 2022/02/20 12:34:42 by gabdoush         ###   ########.fr       */
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
	i = 0;
	while (stack_char[i])
	{
		stack->base_a[i] = ft_atoi(stack_char[i]);
		i++;
	}
	stack->len_a = i;
	checking_duplicated(stack);
/*======================================================================*/
	i = 0;
	while (i < stack->len_b)
	{
		printf("stack->base_b[%d] --> %d\n", i, stack->base_b[i]);
		i++;
	}

	i = 0;
	while (i < stack->len_a)
	{
		printf("stack->base_b[%d] --> %d\n", i, stack->base_a[i]);
		i++;
	}
}

/*======================================================================*/