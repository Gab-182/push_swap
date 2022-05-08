/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:15:43 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/08 10:24:24 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*✅-------------------------------------------------------------------------*/
/**
 * @brief Check the validation of the given argument.
 * positive number or nigative number
 * 
 * @param str 
 */
void	check_digit(char **str)
{
	int	i;

	i = 0;
	while (str[i] && str)
	{
		if (str[i][0] == '-' || str[i][0] == '+')
		{
			if (str[i] && str && str[i][1] && ft_isdigit(str[i][1]) == 1)
			{
				if (str[i + 1] == NULL)
					return ;
				i++;
			}
			else
				error();
		}
		else if (is_number(str[i]) != 1)
			error();
		else if (ft_isdigit(*str[i]) != 1)
			error_with_free(str);
		else
			i++;
	}
	return ;
}

/*✅-------------------------------------------------------------------------*/
/**
 * @brief Check if there any duplicate numbers in the given arguments.
 * 
 * @param stack 
 */
void	checking_duplicated(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < stack->len_a)
	{
		while (j < stack->len_a)
		{
			if (stack->base_a[i] == stack->base_a[j] && stack->base_a[j] != ' ')
				free_stack(stack->base_a, '1');
			j++;
		}
		i++;
		j = i + 1;
	}
}

/*✅-------------------------------------------------------------------------*/
/**
 * @brief check the validation of the given arguments
 * positive number or nigative number.
 * 
 * @param str 
 */
void	check_digit_multi(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (ft_isdigit(str[i + 1]) == 1)
				i++;
			else
				error();
		}
		while (str[i] && str)
		{
			if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
				i++;
			else
				error();
		}
	}
}

/*✅-------------------------------------------------------------------------*/
/**
 * @brief check the validity of using negative or positive signs
 * as an arguments.
 * 
 * @param str 
 */
void	check_negative_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (ft_isdigit(str[i + 1]) == 1)
				i++;
			else
				error();
		}
		i++;
	}
}

/*✅-------------------------------------------------------------------------*/
/**
 * @brief check if the argument is not just spaces
 * @param arg 
 */
void	check_empty(char *arg)
{
	int	i;

	i = 0;
	if (ft_strlen(arg) == 0)
		error();
	while (arg[i])
	{
		if (arg[i] == ' ')
			i++;
		else
			break ;
	}
	if (i == ft_strlen(arg))
		error();
}

/*============================================================================*/