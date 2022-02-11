/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:50:01 by gabdoush          #+#    #+#             */
/*   Updated: 2021/11/02 09:50:32 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current_element;
	t_list	*next_element;

	current_element = *lst;
	if (*lst != NULL)
	{
		while (current_element != NULL)
		{
			next_element = current_element -> next;
			ft_lstdelone(current_element, del);
			current_element = next_element;
		}
	}
	*lst = NULL;
}
