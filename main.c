/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:05:43 by gabdoush          #+#    #+#             */
/*   Updated: 2022/02/20 14:53:47 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	stack.base_a = NULL;
	stack.base_b = (int *)ft_strdup("");
	stack.len_a = 0;
	stack.len_b = 0;
	if (argc == 2)
		push_swap_q(argv[1], &stack);
/*==============================================================*/
	else if(argc > 2)
	{
		/* to move after {./push_swap} */
		argv++;
		push_swap(argv, &stack);
	}
	return (EXIT_SUCCESS);
}
