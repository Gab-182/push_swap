/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:42:10 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/05 10:43:01 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*----------------------------------------------------------------------------*/
/**
 * @brief swap two int number
 * 
 * @param a 
 * @param b 
 */
void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
