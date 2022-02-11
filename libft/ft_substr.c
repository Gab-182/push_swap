/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:05:00 by gabdoush          #+#    #+#             */
/*   Updated: 2022/02/07 20:10:27 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*sub_str;

	if (start > ft_strlen(s) || len <= 0)
		return (ft_strdup(""));
	if ((start + len) > ft_strlen(s))
	{
		sub_str = (char *) ft_calloc(ft_strlen(s) - start + 1, sizeof(char));
		if (!sub_str)
			return (NULL);
		ft_strlcpy(sub_str, s + start, ft_strlen(s) - start + 1);
		return (sub_str);
	}
	sub_str = (char *) ft_calloc(len + 1, sizeof(char));
	if (!sub_str)
		return (NULL);
	ft_strlcpy(sub_str, s + start, len + 1);
	return (sub_str);
}
