/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:45:16 by gabdoush          #+#    #+#             */
/*   Updated: 2022/02/20 22:42:10 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
/*-----------------------------------------------------------*/
	/**
	 * Edit atoi to handle the case when the item is not integer.
	 * Checked on single argument..✅
	 * Not checked on multi_arguments...❌
	 */
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] >= 'z') || (str[i] >= 'A' && str[i] >= 'Z'))
		{
			ft_putstr("ERROR, digit(char in ft_atoi)\n");
			free(str);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	i = 0; // resetting i to 0 to prepare it to the next operation.
/*-----------------------------------------------------------*/
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (sign * num);
}
