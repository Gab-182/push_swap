/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:49:17 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/07 14:35:27 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*----------------------------------------------------------------------------*/
/**
 * @brief  Display "Error" message on the standard error
 */
void	error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

/*----------------------------------------------------------------------------*/
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

/*----------------------------------------------------------------------------*/
void	error_with_free(char **str)
{
	free(str);
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

/*============================================================================*/