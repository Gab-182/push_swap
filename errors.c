/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:49:17 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/08 15:27:40 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*✅-------------------------------------------------------------------------*/
/**
 * @brief  Display "Error" message on the standard error
 */
void	error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

/*✅-------------------------------------------------------------------------*/
/**
 * @brief free integer array and exit the program according to the flag.
 * 
 * @param stack 
 * @param flag 
 */
void	free_stack(int *stack, char flag)
{
	if (flag == 'e')
	{
		if (stack)
			free(stack);
		stack = NULL;
		exit(EXIT_FAILURE);
	}
	else if (flag == '1')
	{
		free(stack);
		stack = NULL;
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (stack)
			free(stack);
		stack = NULL;
	}
}

/*✅-------------------------------------------------------------------------*/
void	error_with_free_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

/*✅-------------------------------------------------------------------------*/
void	error_with_free_1d(char *str)
{
	free(str);
	str = NULL;
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

/*============================================================================*/