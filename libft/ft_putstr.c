/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:40:00 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/05 10:41:14 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief print a character using write() function.
 * 
 * @param c 
 */
void	ft_putchar(int c)
{
	write (1, &c, 1);
}

/*----------------------------------------------------------------------------*/
/**
 * @brief printf string of characters using ft_putchar() function.
 * 
 * @param s 
 */
void	ft_putstr(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

/*============================================================================*/