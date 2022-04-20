/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:54:53 by gabdoush          #+#    #+#             */
/*   Updated: 2022/04/20 16:56:15 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*s2;
	size_t	n;

	s2 = (char *)malloc(ft_strlen(s1) + 1);
	n = 0;
	if (!s2)
	{
		return (NULL);
	}
	while (n < ft_strlen(s1))
	{
		s2[n] = ((char *)s1)[n];
		n++;
	}
	s2[n] = '\0';
	//free(s1);
	return (s2);
}
